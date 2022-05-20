class Solution {
public:
    // looked at the solution 
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        int longP = 1;
        // it allocates "row" elements of vector<int> and initialize each of them to vector<int>(col, -1)
        // vector<int>(col,-1) allocates "col" elements of int and initialize each of them to -1
        vector<vector<int>> dp(row, vector<int>(col, -1));
        
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                if(dp[i][j] == -1) longP = max(longP, dfsFunc(matrix, dp, i, j, row, col));
            }
        }
        
        return longP;
    }
    
    bool inBoundary(int i, int j, int row, int col) {
        return (i >=0 && j >= 0 && i < row && j < col);
    }

    
    int dfsFunc(vector<vector<int>> &matrix, vector<vector<int>> &dp, int i, int j, int row, int col) {
        if(!inBoundary(i,j,row,col)) return 0;
        
        // already processed, contains longest path from current i and j
        if(dp[i][j] != -1) return dp[i][j];
        
        int p1 = 0, p2 = 0, p3 = 0, p4 = 0;
        
        if(inBoundary(i+1, j, row, col) && matrix[i+1][j] > matrix[i][j]) p1 = dfsFunc(matrix,dp,i+1,j,row,col);
        if(inBoundary(i-1, j, row, col) && matrix[i-1][j] > matrix[i][j]) p2 = dfsFunc(matrix,dp,i-1,j,row,col);
        if(inBoundary(i, j+1, row, col) && matrix[i][j+1] > matrix[i][j]) p3 = dfsFunc(matrix,dp,i,j+1,row,col);
        if(inBoundary(i, j-1, row, col) && matrix[i][j-1] > matrix[i][j]) p4 = dfsFunc(matrix,dp,i,j-1,row,col);
        
        dp[i][j] = max(p1,max(p2,max(p3,p4))) + 1;
        
        return dp[i][j];

    }
    
    
};
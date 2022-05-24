class Solution {
public:
    int uniquePaths(int m, int n) {
        int row = m;
        int col = n;
        vector<vector<int>> matrix(row,vector<int>(col,-1)); // matrix to store current available paths at current pos
        
        return findPaths(0,0,row,col,matrix);
    }
        
    int findPaths(int i, int j, int row, int col, vector<vector<int>>& matrix) {
        if(!inRange(i,j,row,col)) return 0;
        if(i == row - 1 && j == col - 1) return 1; // when reached the end, return 1
        if(matrix[i][j] != -1) return matrix[i][j]; // if already processed, return current available paths
        
        int p1 = 0, p2 = 0;
        if(inRange(i+1,j,row,col)) p1 = findPaths(i+1,j,row,col,matrix);
        if(inRange(i,j+1,row,col)) p2 = findPaths(i,j+1,row,col,matrix);
        
        return matrix[i][j] = p1 + p2; // now this pos holds available paths from curr pos to the end
    }
    
    bool inRange(int i, int j, int row, int col) {return (i < row && j < col);}
};
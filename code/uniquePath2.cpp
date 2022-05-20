#include <vector>
#include <iostream>
using namespace std;

class UniquePath {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        // initialize all elements in vector to -1
        int row = obstacleGrid.size();
        int col = obstacleGrid[0].size();
        vector<vector<int>> dp(row,vector<int>(col,-1));
        
        return dfsFunc(0,0,row,col,obstacleGrid, dp);
    }
    
    bool inBoundary(int i, int j, int row, int col) {
        return (i < row && j < col);
    }
    
    int dfsFunc(int i, int j, int row, int col, vector<vector<int>>& obstacleGrid, vector<vector<int>>&dp) {
        if(obstacleGrid[i][j]) return 0; //if curr element is obstacle 
        if(dp[i][j] != -1) return dp[i][j]; // if already processed
        if(i == row-1 && j == col -1) return 1; //if reached at the end and is not obstacle
        
        int p1 = 0, p2 = 0;
        
        if(inBoundary(i+1,j,row,col) && obstacleGrid[i+1][j] == 0) p1 = dfsFunc(i+1,j,row,col,obstacleGrid, dp);
        if(inBoundary(i,j+1,row,col) && obstacleGrid[i][j+1] == 0) p2 = dfsFunc(i,j+1,row,col,obstacleGrid, dp);
        
        // dp[i][j] holds how many ways there are to get to the bottom right destination from curr position
        return dp[i][j] = p1 + p2;
    }
};

int main() {
    vector<vector<int>> obstacleGrid = {{0,0,0,0,0,1,0,1,0,0,0,0,1,0,0,0,0,0},{0,0,0,0,0,0,1,0,0,0,0,1,0,1,0,1,0,0},
    {1,0,0,0,0,0,1,0,0,0,0,0,1,0,1,1,0,1},{0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0},{0,0,0,0,0,1,0,0,0,0,1,1,0,1,0,0,0,0},{1,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,0},
    {0,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,0,0},{0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {1,1,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0},{0,0,1,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0},{0,1,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0},
    {0,0,1,0,0,0,0,1,0,0,0,0,0,1,0,0,0,1},{0,1,0,1,0,1,0,0,0,0,0,0,0,1,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1},
    {1,0,1,1,0,0,0,0,0,0,1,0,1,0,0,0,1,0},{0,0,0,1,0,0,0,0,1,1,1,0,0,1,0,1,1,0},{0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,1,1,0,0,1,0,0,0,0,0,0,0,1,1,0,0,0},{0,0,0,0,0,0,1,0,1,0,0,1,0,1,1,1,0,0},{0,0,0,1,0,0,0,0,0,0,0,0,0,0,1,0,1,1},
    {0,1,0,0,0,0,0,0,0,0,1,0,1,0,1,0,1,0},{1,0,0,1,0,1,0,0,1,0,0,0,0,0,0,0,0,0},{0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0},
    {0,1,0,0,0,0,0,1,0,0,0,0,0,0,1,1,1,0},{1,0,1,0,1,0,0,0,0,0,0,1,1,0,0,0,0,1},{1,0,0,0,0,0,1,1,0,0,0,1,0,0,0,0,0,0}};
    vector<vector<int>> obstacleGrid2 = {{0,0,0}, {0,1,0},{0,0,0}};

    UniquePath solution;
    int ans = solution.uniquePathsWithObstacles(obstacleGrid2);
    cout<<"ans is: " << ans <<endl;
    return 0; 
}

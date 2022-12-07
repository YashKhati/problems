// Recurssive Approach 

class Solution {
public:
    int getSum(vector<vector<int>>& grid,int row,int col)
    {
        if(row < 0 || col <0)
        {
            return INT_MAX;
        }
        if(row==0 && col == 0)
        {
            return grid[row][col];
        }
        return grid[row][col] + min(getSum(grid,row-1,col),getSum(grid,row,col-1));
    }
    int minPathSum(vector<vector<int>>& grid)
    {
        int row =grid.size();
        int col=grid[0].size();
        return getSum(grid,row-1,col-1);      
    }
};

// Memoization Approach

class Solution {
public:
    int getSum(vector<vector<int>>& grid,int row,int col,vector<vector<int>>& dp)
    {
        if(row < 0 || col <0)
        {
            return INT_MAX;
        }
        if(row==0 && col == 0)
        {
            return grid[row][col];
        }
        if(dp[row][col] != -1 )
        {
            return dp[row][col];
        }
        return dp[row][col]=grid[row][col] + min(getSum(grid,row-1,col,dp),getSum(grid,row,col-1,dp));
    }
    int minPathSum(vector<vector<int>>& grid)
    {
        int row =grid.size();
        int col=grid[0].size();
        vector<vector<int>> grid2(row,vector<int> (col,-1));
        return getSum(grid,row-1,col-1,grid2);      
    }
};

// Tabulation approach

class Solution {
public:
    
    int minPathSum(vector<vector<int>>& grid)
    {
        int row =grid.size();
        int col=grid[0].size();
        vector<vector<int>> dp(row,vector<int> (col,-1));
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(i==0 && j==0)
                {
                    dp[i][j]=grid[i][j];
                }
                else if(i==0)
                {
                    dp[i][j]=grid[i][j]+dp[i][j-1];
                }
                else if(j==0)
                {
                    dp[i][j]=grid[i][j]+dp[i-1][j];
                }
                else
                {
                    dp[i][j]=grid[i][j]+min(dp[i-1][j],dp[i][j-1]);
                }
            }   
        }
        return dp[row-1][col-1];      
    }
};

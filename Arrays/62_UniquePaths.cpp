/*
There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). 
The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.
*/

// Recurssive Solution
// TC = O(2^n)
// SC = O(n) 
    // Approach 1 -> destination to start
    int CalcUnique(int m,int n)
    {
        if(m<0 || n<0)
        {
            return 0;
        }
        if(m==0 || n==0)
        {
            return 1;    
        }
        return  CalcUnique(m-1,n)+CalcUnique(m,n-1) ;       
    }
        
    int uniquePaths(int m, int n)
    {
        
        return CalcUnique(m-1,n-1);      
    }


    // Approach 2 -> start to destination 

    int solve(int i,int j,int m,int n)
    {
        if(i==m||j==n)
            return 0;
        if(i==m-1 && j==n-1)
            return 1;

        return solve(i+1,j,m,n) + solve(i,j+1,m,n);
    }
    int uniquePaths(int m, int n) 
    {
        return solve(0,0,m,n) ;
    }


// Memoization Solution
// TC = O(m * n)
// SC = O(m * n) 


int CalcPath(int i,int j,int m,int n,vector<vector<int>> &dp)
    {
        if(i>=m||j>=n)
            return 0;
        if(i==m-1&&j==n-1)
            return 1;
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        return dp[i][j]=CalcPath(i+1,j,m,n,dp)+CalcPath(i,j+1,m,n,dp);
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return CalcPath(0,0,m,n,dp);
    }


// Tabulation Solution
// TC = O(m * n)
// SC = O(m * n) 


class Solution {
public:
    
    int uniquePaths(int m, int n) 
    {
        int dp[m][n];
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==0 || j==0)
                {
                    dp[i][j]=1;
                }
                else
                {
                    dp[i][j]=dp[i-1][j]+dp[i][j-1];
                }
            }
        }
        return dp[m-1][n-1];
    }
}  

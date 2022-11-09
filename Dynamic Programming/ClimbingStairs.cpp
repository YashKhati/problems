//    Recursion Method
// TC = O(2^n)
// SC = O(n)
class Solution {
public:
    int climbStairs(int n)
    {
        return NumberOfWays(n);
    }
     int NumberOfWays(int n)
    {
        if(n==0)
        {
            return 1;
        }
        if(n<0)
        {
            return 0;
        }
        return NumberOfWays(n-1)+NumberOfWays(n-2);
    }
};


// Memoization Method
// TC = O(n)
// SC = O(n)

class Solution {
public:
    int climbStairs(int n)
    {
        vector<int> dp(n+1,0);
        return NumberOfWays(n,dp);
    }
     int NumberOfWays(int n,vector<int> &dp)
    {
        if(n<=2)
        {
            return dp[n]=n;
        }
        if(dp[n]!=0)
        {
            return dp[n];
        }
        return dp[n]=NumberOfWays(n-1,dp)+NumberOfWays(n-2,dp);
    }
};

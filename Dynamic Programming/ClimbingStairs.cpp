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
// SC = O(2n)

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

// Dynamic Programming
// TC =O(n);
// SC = O(n);

class Solution {
public:
    int climbStairs(int n)
    {
        vector<int> dp(n+1,0);
        return NumberOfWays(n,dp);
    }
    
    int NumberOfWays(int n,vector<int> &dp)
    {
        for(int i=0;i<=n;i++)
        {
            if(i<=2)
            {
                dp[i]=i;
                continue;
            }
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
};


// Optimize Code Dp
// TC=O(n)
// SC=O(1)

class Solution {
public:
    int climbStairs(int n)
    {
        vector<int> dp(2,0);
        return NumberOfWays(n,dp);
    }
    
    int NumberOfWays(int n,vector<int> &dp)
    {
        dp[1]=1;
        dp[0]=0;
        for(int i=1;i<=n;i++)
        {
            int ans = dp[0]+dp[1];
            dp[0]=dp[1];
            dp[1]=ans;
        }
        return dp[1];
    }
};

class Solution {
public:

    int climbStairs(int n) {
        if(n==0){
            return 0;
        }
        int a=0,b=1,c{};
        for(int i=1;i<=n;i++){
            c=a+b;
            a=b;
            b=c;
        }
        return b;
    }

};

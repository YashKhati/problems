//    Recursion Method
// TC = O(2^n)
// SC = O(n)
class Solution {
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
    public int climbStairs(int n) 
    {
        return NumberOfWays(n);
    }
}

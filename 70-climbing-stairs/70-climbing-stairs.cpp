class Solution {
public:
    
    int help(int n,vector<int>&dp)
    {
        if(n==0)
        {
            return 1;
        }
        if(dp[n]!=-1)
        {
            return dp[n];
        }
        return dp[n] = help(n-1,dp) + help(n-2,dp);
    }
    
    int climbStairs(int n) {
        if(n<=2)
        {
            return n;
        }
        vector<int>dp(n+1,-1);
        dp[1]=1;
        dp[2]=2;
        return help(n,dp);
        
    }
};
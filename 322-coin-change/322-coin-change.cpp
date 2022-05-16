class Solution {
public:
    
    int help(int n , int amount , vector<vector<int>>&dp,vector<int>&coins)
    {
        if(n<=0)
        {
            return 1e9;
        }
        if(amount==0)
        {
            return 0;
        }
        if(dp[n][amount]!=-1)
        {
            return dp[n][amount];
        }
        
        if(coins[n-1]>amount)
        {
            return dp[n][amount] = help(n-1,amount,dp,coins);
        }
        else{
            return dp[n][amount] = min(help(n-1,amount,dp,coins), 1 + help(n,amount-coins[n-1],dp,coins));
        }
        
        
    }
    
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
        
         int ans = help(n,amount,dp,coins);
        return ans==1e9 ? -1:ans;
    }
};
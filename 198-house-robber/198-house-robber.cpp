class Solution {
public:
    int help(int n,vector<int>&nums,vector<int>&dp)
    {
          if(n<0)
          {
              return 0;
          }
         if(dp[n]!=-1)
         {
             return dp[n];
         }
          int l = help(n-2,nums,dp) + nums[n];
          int r = help(n-1,nums,dp);
        
          return dp[n] = max(l,r);
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,-1);
        return help(n-1,nums,dp);
    }
};
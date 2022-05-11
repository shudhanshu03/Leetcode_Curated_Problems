class Solution {
public:
    int help(vector<int>&res)
    {
        int n = res.size();
         vector<int>dp(n,-1);
        dp[0] = res[0];
        dp[1] = max(res[0],res[1]);
        
        for(int i=2;i<n;i++)
        {
            dp[i] = max(dp[i-1],res[i]+dp[i-2]);
        }
        return dp[n-1];
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        if(n==1)
        {
            return nums[0];
        }
        if(n==2)
        {
            return max(nums[0],nums[1]);
        }
        vector<int>tb(nums.begin(),nums.end()-1);
        vector<int>tbb(nums.begin()+1,nums.end());
        
        
        return max(help(tb),help(tbb));
    }
};
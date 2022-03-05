class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        
        int n = nums.size();
        int maxe = -1;
        for(int i=0;i<n;i++)
        {
            maxe = max(maxe,nums[i]);
        }
        
        vector<int>sum(maxe+1,0);
        vector<int>dp(maxe+1,0);
        for(int i=0;i<n;i++)
        {
            sum[nums[i]]+=nums[i];
        }
        
        dp[1] = sum[1];
        for(int i=2;i<=maxe;i++)
        {
            dp[i] = max(dp[i-2]+sum[i],dp[i-1]);
        }
        return max(dp[maxe],dp[maxe-1]);
        
        
    }
};
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        int j=0;
        int res = 0;
        int ans = 0;
        unordered_set<int>s;
        for(int i=0;i<n;i++)
        {
            while(s.find(nums[i])!=s.end())
            {
                s.erase(nums[j]);
                ans = ans-nums[j];
                j++;
            }
            s.insert(nums[i]);
            ans = ans+nums[i];
            res = max(ans,res);
        }
        return res;
    }
};
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxsofar = nums[0];
        int currentmax = nums[0];
        
        for(int i=1;i<nums.size();i++)
        {
            currentmax = max(nums[i],nums[i]+currentmax);
            maxsofar = max(maxsofar,currentmax);
        }
        return maxsofar;
    }
};
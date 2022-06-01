class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int>v;
        int sum = 0;
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            v.push_back(sum);
        }
        return v;
    }
};
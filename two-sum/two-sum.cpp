class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>m;
        int n = nums.size();
        vector<int>res;
        for(int i=0;i<n;i++)
        {
            if(m.find(target-nums[i])!=m.end())
            {
                res.push_back(i);
                res.push_back(m[target-nums[i]]);
            }
            else{
                m[nums[i]]=i;
            }
        }
        return res;
    }
};
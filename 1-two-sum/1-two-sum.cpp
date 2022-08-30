class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
      unordered_map<int,int>m;
        
        vector<int>res;
        for(int i=0;i<nums.size();i++)
        {
            if(m.find(target-nums[i])!=m.end())
            {
                 res.push_back(i);
                res.push_back(m[target-nums[i]]);
               
        
            }
            m[nums[i]]=i;
        }
       
        return res;
    }
};
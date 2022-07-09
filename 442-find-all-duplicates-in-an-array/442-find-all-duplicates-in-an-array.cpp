class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int>res;
        for(int i=0;i<nums.size();i++)
        {
            int temp = abs(nums[i])-1;
            
            if(nums[temp]<0)
            {
                res.push_back(abs(nums[i]));
            }
            nums[temp]*=-1;
        }
        
        return res;
    }
};
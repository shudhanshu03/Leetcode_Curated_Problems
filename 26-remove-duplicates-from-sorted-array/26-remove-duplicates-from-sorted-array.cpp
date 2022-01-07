class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        set<int>s;
        
        for(int i=0;i<nums.size();i++)
        {
            s.insert(nums[i]);
        }
        vector<int>res;
        for(auto i:s)
        {
            res.push_back(i);
        }
        for(int i=0;i<s.size();i++)
        {
            nums[i]=res[i];
        }
        return s.size();
    }
};
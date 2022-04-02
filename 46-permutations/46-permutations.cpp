class Solution {
public:
    void helper(vector<vector<int>>&res, vector<int>&nums , int l , int r)
    {
        if(l==r)
        {
            res.push_back(nums);
            return;
        }
        
        for(int i=l;i<=r;i++)
        {
            swap(nums[l],nums[i]);
            
            helper(res,nums,l+1,r);
            
            swap(nums[l],nums[i]);
            
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>res;
        
        helper(res,nums,0,nums.size()-1);
        
        return res;
    }
};
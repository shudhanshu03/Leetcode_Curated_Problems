class Solution {
public:
    
    void help(vector<int>& nums,vector<vector<int>>&res,int l,int r)
    {
        if(l==r)
        {
            res.push_back(nums);
            return;
        }
        
        for(int i=l;i<=r;i++)
        {
            swap(nums[l],nums[i]);
            help(nums,res,l+1,r);
            swap(nums[l],nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>res;
        
        help(nums,res,0,nums.size()-1);
        
        return res;
    }
};
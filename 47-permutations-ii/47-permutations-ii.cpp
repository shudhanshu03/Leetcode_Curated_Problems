class Solution {
public:
    
    
    void helper(vector<vector<int>>&res , vector<int>&nums,int l , int r)
    {
        if(l==r)
        {
            res.push_back(nums);
            return;
        }
        set<int>s;
        for(int i=l;i<=r;i++)
        {
            if(s.find(nums[i])!=s.end())
            {
                continue;
            }
            s.insert(nums[i]);
            swap(nums[l],nums[i]);
            helper(res,nums,l+1,r);
            swap(nums[l],nums[i]);
            
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>res;
        helper(res,nums,0,nums.size()-1);
        
        return res;
    }
};
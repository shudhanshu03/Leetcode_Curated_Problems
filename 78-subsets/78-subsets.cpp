class Solution {
public:
    void solve(int i, vector<int>&v , vector<vector<int>>&ans , vector<int>&nums)
    {
        if(i==nums.size())
        {
            ans.push_back(v);
            return;
        }
        
        v.push_back(nums[i]);
        solve(i+1,v,ans,nums);
        v.pop_back();
        solve(i+1,v,ans,nums);
    }
    
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>v;
        vector<vector<int>>ans;
        
        solve(0,v,ans,nums);
        
        return ans;
        
    }
};
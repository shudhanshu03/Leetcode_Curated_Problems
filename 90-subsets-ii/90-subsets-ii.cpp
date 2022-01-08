class Solution {
public:
    
    void solve(int i,vector<int>&v,vector<vector<int>>&ans,vector<int>&nums)
    {
        if(i==nums.size())
        {
            ans.push_back(v);
            return;
        }
        
        v.push_back(nums[i]);    
        solve(i+1,v,ans,nums);
                
        v.pop_back();
        while(i+1 < nums.size() && nums[i]==nums[i+1])
        {
            i++;
        }
        solve(i+1,v,ans,nums);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>v;
        vector<vector<int>>ans;
        
        solve(0,v,ans,nums);
        
        return ans;
    }
};
class Solution {
public:
    void solve(int i,vector<int>&temp,vector<vector<int>>&res,vector<int>&candidates,int target)
    {
        if(target==0)
        {
            res.push_back(temp);
            return;
        }
        if(i==candidates.size())
        {
            return;
        }
        if(target < 0)
        {
            return;
        }
        
        solve(i+1,temp,res,candidates,target);
        
        temp.push_back(candidates[i]);
        
        solve(i,temp,res,candidates,target-candidates[i]);
        
        temp.pop_back();
        
        
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>res;
        vector<int>temp;
        
        solve(0,temp,res,candidates,target);
        
        return res;
        
        
    }
};
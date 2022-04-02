class Solution {
public:
    
    void helper(vector<vector<int>>&res , vector<int>&temp , vector<int>&candidates, int target , int i)
    {
        if(i>=candidates.size())
        {
            return;
        }
        if(target<0)
        {
            return;
        }
        if(target==0)
        {
            res.push_back(temp);
            return;
        }
        
        temp.push_back(candidates[i]);
        helper(res,temp,candidates,target-candidates[i],i);
        temp.pop_back();
        helper(res,temp,candidates,target,i+1);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>res;
        vector<int>temp;
        
        helper(res,temp,candidates,target,0);
        return res;
    }
};
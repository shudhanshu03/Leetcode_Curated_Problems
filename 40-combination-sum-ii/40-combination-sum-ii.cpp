class Solution {
public:
   void solve(int i,vector<int>&temp,vector<vector<int>>&res,vector<int>&candidates,int target)
    {
        if(target==0)
        {
            res.push_back(temp);
            return;
        }
       if(target < 0)
       {
return;
           }
        if(i>=candidates.size())
        {
            return;
        }
        
        
        
          temp.push_back(candidates[i]);
        
          solve(i+1,temp,res,candidates,target-candidates[i]);
        
          temp.pop_back();
            
          while(i+1 < candidates.size() && candidates[i]==candidates[i+1])
            {
              i++;
            }
           solve(i+1,temp,res,candidates,target);
            
          
  }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>res;
        vector<int>temp;
        sort(candidates.begin(),candidates.end());
        solve(0,temp,res,candidates,target);
        
        return res;
    }
};
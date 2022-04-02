class Solution {
public:
    void helper(vector<vector<int>>&res,vector<int>&temp,int start,int n , int k)
    {
        if(n<0)
        {
            return;
        }
        if(temp.size()==k && n==0)
        {
            res.push_back(temp);
            return;
        }
        
        for(int i = start; i<=9;i++)
        {
            temp.push_back(i);
            helper(res,temp,i+1,n-i,k);
            temp.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>res;
        vector<int>temp;
        helper(res,temp,1,n,k);
        
        return res;
    }
};
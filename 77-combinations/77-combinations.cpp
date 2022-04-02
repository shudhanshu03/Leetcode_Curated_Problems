class Solution {
public:
    
    void helper(vector<vector<int>>&res,vector<int>&temp,int start , int limit , int n, int k)
    {
        if(limit==k)
        {
            res.push_back(temp);
            return;
        }
        
        for(int i=start;i<=n;i++)
        {
            temp.push_back(i);
            helper(res,temp,i+1,limit+1,n,k);
            temp.pop_back();
        }
    }
    
    vector<vector<int>> combine(int n, int k) {
        if(n<k)
        {
            return {};
        }
        vector<int>temp;
        vector<vector<int>>res;
        helper(res,temp,1,0,n,k);
        return res;
    }
};
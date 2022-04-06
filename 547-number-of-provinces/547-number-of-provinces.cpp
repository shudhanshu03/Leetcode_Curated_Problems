class Solution {
public:
    
    void helper(int start , int &res , vector<bool>&vis , vector<vector<int>>&isConnected)
    {
        vis[start]=1;
        for(int i=0;i<isConnected.size();i++)
        {
            if(isConnected[start][i]==1 && vis[i]==0)
            {
                helper(i,res,vis,isConnected);
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int n = isConnected.size();
        vector<bool>vis(n,0);
        
        int res = 0;
        
        for(int i=0;i<n;i++)
        {
            if(vis[i]==0)
            {
                res++;
                helper(i,res,vis,isConnected);
            }
        }
        return res;
    }
};
class Solution {
public:
    
    void dfs(int ii , vector<bool>&vis, vector<vector<int>>&isConnected)
    {
        vis[ii]=1;
        
        for(int i=0;i<isConnected.size();i++)
        {
            if(isConnected[ii][i]==1 && vis[i]==0)
            {
                dfs(i,vis,isConnected);
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        
        vector<bool>vis(n,0);
        int c=0;
        for(int i=0;i<n;i++)
        {
            if(vis[i]==0)
            {
                c++;
                dfs(i,vis,isConnected);
            }
        }
        return c;
    }
};
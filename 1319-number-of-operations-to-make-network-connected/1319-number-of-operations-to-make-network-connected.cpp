class Solution {
public:
    void dfs(int i, vector<bool>&vis,vector<vector<int>>&graph)
    {
        vis[i]=1;
        
        for(auto q:graph[i])
        {
            if(vis[q]==0)
            {
                dfs(q,vis,graph);
            }
        }
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        int wires = connections.size();
        
        if(wires<n-1)
        {
            return -1;
        }
        
        vector<vector<int>>graph(n);
        for(int i=0;i<wires;i++)
        {
            graph[connections[i][0]].push_back(connections[i][1]);
            graph[connections[i][1]].push_back(connections[i][0]);
        }
        int c=0;
        vector<bool>vis(n,0);
        for(int i=0;i<n;i++)
        {
            if(vis[i]==0)
            {
                c++;
                dfs(i,vis,graph);
            }
        }
        return c-1;
    }
};
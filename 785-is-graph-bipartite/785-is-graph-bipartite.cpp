class Solution {
public:
    bool dfs(vector<int>&color,vector<vector<int>>& graph,int i)
    {
        if(color[i]==-1)
        {
            color[i]=1;
        }
        for(auto q:graph[i])
        {
            if(color[q]==-1)
            {
                color[q] = 1-color[i];
                if(dfs(color,graph,q)==false)
                {
                    return false;
                }
            }
            else{
                if(color[q]==color[i])
                {
                    return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>color(n,-1);
        
        for(int i=0;i<n;i++)
        {
            if(color[i]==-1)
            {
                if(dfs(color,graph,i)==false)
                    return false;
            }
        }
        return true;
    }
};
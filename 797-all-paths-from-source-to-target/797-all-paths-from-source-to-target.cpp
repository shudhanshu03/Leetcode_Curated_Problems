class Solution {
public:
    void dfs(int i , int n , vector<vector<int>>&res,vector<int>&temp, vector<vector<int>>&graph)
    {
        temp.push_back(i);
        if(i==n-1)
        {
            res.push_back(temp);
            temp.pop_back();
            return;
        }
        
        for(auto q:graph[i])
        {
            dfs(q,n,res,temp,graph);
        }
        
        temp.pop_back();
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        
        vector<vector<int>>res;
        vector<int>temp;
        dfs(0,n,res,temp,graph);
        
        return res;
    }
};
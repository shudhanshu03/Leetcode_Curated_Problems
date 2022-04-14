class Solution {
public:
    
    bool dfs(int i, vector<bool>&vis, vector<bool>&currwin , vector<vector<int>>&graph)
    {
        vis[i]=1;
        currwin[i]=1;
        
        for(auto q:graph[i])
        {
            if(vis[q]==0)
            {
                if(dfs(q,vis,currwin,graph))
                {
                    return true;
                }
            }
            else if(currwin[q])
            {
                return true;
            }
        }
        
        currwin[i]=0;
        return false;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>graph(numCourses);
        
        for(int i=0;i<prerequisites.size();i++)
        {
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        vector<bool>vis(numCourses);
        vector<bool>currwin(numCourses);
        
        for(int i=0;i<numCourses;i++)
        {
            if(vis[i]==0)
            {
                if(dfs(i,vis,currwin,graph))
                {
                    return false;
                }
            }
        }
        return true;
    }
};
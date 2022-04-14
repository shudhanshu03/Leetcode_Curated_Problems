class Solution {
public:
    bool dfs(int i , stack<int>&s , vector<vector<int>>&graph,vector<int>&vis,vector<bool>&currwin)
    {
        vis[i]=1;
        currwin[i]=1;
        
        for(auto q:graph[i])
        {
            if(vis[q]==false)
            {
                if(dfs(q,s,graph,vis,currwin))
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
        s.push(i);
        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = prerequisites.size();
        vector<vector<int>>graph(numCourses);
        
        for(int i=0;i<n;i++)
        {
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        stack<int>s;
        vector<int>res;
        vector<int>vis(numCourses,0);
        vector<bool>currwin(numCourses,0);
        bool flag=0;
        for(int i=0;i<numCourses;i++)
        {
            if(vis[i]==false)
            {
                if(dfs(i,s,graph,vis,currwin))
                {
                    flag=1;
                    break;
                }
            }
                   
        }
        if(flag)
        {
            return {};
        }
        while(s.empty()==false)
        {
            res.push_back(s.top());
            s.pop();
        }
        return res;
        
    }
};
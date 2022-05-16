class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int res = INT_MAX;
        int n = grid.size();
        queue<pair<int,pair<int,int>>>q;
        vector<vector<int>>vis(n,vector<int>(n,0));
        vector<vector<int>>dir = {{-1,0},{1,0},{0,-1},{0,1},{1,1},{-1,-1},{-1,1},{1,-1}};
        
        if(grid[0][0]==1)
        {
            return -1;
        }
        
        q.push({1,{0,0}});
        vis[0][0]=1;
        bool flag=0;
        while(q.empty()==false)
        {
            auto it = q.front();
            q.pop();
            int val = it.first;
            int indexi = it.second.first;
            int indexj = it.second.second;
            
            if(indexi==n-1 && indexj==n-1)
            {
                res = min(res,val);
            }
            for(auto i:dir)
            {
                int newx = i[0]+indexi;
                int newy = i[1]+indexj;
                
                if(newx>=0 && newx<n && newy>=0 && newy<n && vis[newx][newy]==0 && grid[newx][newy]==0)
                {
                    q.push({val+1,{newx,newy}});
                    vis[newx][newy]=1;
                }
            }
            
            
        }
        return res==INT_MAX?-1:res;
        
        
        
    }
};
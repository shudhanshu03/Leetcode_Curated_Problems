class Solution {
public:
    
    void dfs(int i ,int j , vector<pair<int,int>>&r , vector<vector<int>>&grid)
    {
        if(i<0 || i>=grid.size() || j<0 || j>=grid.size() || grid[i][j]==0)
        {
            return;
        }
        grid[i][j]=0;
        r.push_back({i,j});
        dfs(i+1,j,r,grid);
        dfs(i-1,j,r,grid);
        dfs(i,j+1,r,grid);
        dfs(i,j-1,r,grid);
    }
    
    int shortestBridge(vector<vector<int>>& grid) {
        vector<pair<int,int>>x;
        vector<pair<int,int>>y;
        int qx = -1, qy=-1;
        int c = 0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid.size();j++)
            {
                if(grid[i][j]==1)
                {
                    c++;
                    if(c==1)
                   {
                    dfs(i,j,x,grid);
                   }
                   else if(c==2)
                   {
                     dfs(i,j,y,grid);
                   }
                }
                
                
                
                
            }
        }
        int res = INT_MAX;
        for(int i=0;i<x.size();i++)
        {
            for(int j=0;j<y.size();j++)
            {
                int q = abs(x[i].first-y[j].first) + abs(x[i].second-y[j].second) - 1;
                res = min(res,q);
            }
        }
        return res;
        
    }
};
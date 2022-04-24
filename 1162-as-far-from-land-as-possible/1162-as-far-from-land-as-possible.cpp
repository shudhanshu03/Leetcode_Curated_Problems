class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        vector<vector<int>>dir={{-1,0},{1,0},{0,1},{0,-1}};
        queue<pair<int,int>>q;
        int res = 0;
        
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid.size();j++)
            {
                if(grid[i][j]==1)
                {
                    q.push({i,j});
                }
            }
        }
        
        while(q.empty()==false)
        {
            auto it = q.front();
            q.pop();
            
            int currx = it.first;
            int curry = it.second;
            
            for(auto di:dir)
            {
                int newx = currx + di[0];
                int newy = curry + di[1];
                
                if(newx>=0 && newx<grid.size() && newy>=0 && newy<grid.size() && grid[newx][newy]==0)
                {
                    q.push({newx,newy});
                    grid[newx][newy] = grid[currx][curry] +1 ;
                    res = max(res,grid[newx][newy]);
                }
            }
        }
        
        return res>0 ? res-1 : -1;
        
        
    }
};
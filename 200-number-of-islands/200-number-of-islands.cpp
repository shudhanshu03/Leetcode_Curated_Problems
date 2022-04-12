class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int c = 0;
        if(grid.size()==0)
        {
            return 0;
        }
        vector<vector<int>>dir = {{0,1},{0,-1},{1,0},{-1,0}};
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='1')
                {
                    c++;
                    
                    
                    q.push({i,j});
                    
                    while(q.empty()==false)
                    {
                        auto qq  = q.front();
                        q.pop();
                        int ii = qq.first;
                        int jj = qq.second;
                        
                        if(grid[ii][jj]=='1')
                        {
                            grid[ii][jj]='0';
                            for(auto di:dir)
                            {
                                int a = di[0]+ii;
                                int b = di[1]+jj;
                                
                                if(a>=0 && a<n && b>=0 && b<m)
                                {
                                    q.push({a,b});
                                }
                            }
                        }
                    }
                }
            }
        }
        return c;
    }
};
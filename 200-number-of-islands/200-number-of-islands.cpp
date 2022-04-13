class Solution {
public:
    
    void dfs(int i, int j , int m , int n , vector<vector<char>>&grid)
    {
        if(i>=m || i<0 || j>=n || j<0 || grid[i][j]=='0')
        {
            return;
        }
        grid[i][j]='0';
        dfs(i+1,j,m,n,grid);
        dfs(i-1,j,m,n,grid);
        dfs(i,j+1,m,n,grid);
        dfs(i,j-1,m,n,grid);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int c = 0;
        int m = grid.size();
        int n = grid[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]=='1')
                {
                    c++;
                    dfs(i,j,m,n,grid);
                }
            }
        }
        return c;
    }
};
class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        for(int i=0; i<k; i++)
        {
            int temp = grid[n-1][m-1];
            for(int j= n-1; j>=0; j--)
            {
                for(int k=m-1; k>=0; k--)
                {
                    if(j == n-1 && k== m-1) continue;
                    if(k == m-1) 
                    {
                        grid[j+1][0] = grid[j][k];
                        continue;
                    }
                    grid[j][k+1] = grid[j][k];
                }
            }
            grid[0][0] = temp;
        }
        return grid;
    }
};
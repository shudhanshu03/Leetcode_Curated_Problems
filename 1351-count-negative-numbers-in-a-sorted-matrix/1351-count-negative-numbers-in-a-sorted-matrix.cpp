class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int l = 0,h=n-1;
        int ans = 0;
        while(l<m)
        {
            while(h>=0 && grid[l][h] < 0)
            {
                h--;
            }
            ans+=n-h-1;
            l++;
        }
        return ans;
    }
};
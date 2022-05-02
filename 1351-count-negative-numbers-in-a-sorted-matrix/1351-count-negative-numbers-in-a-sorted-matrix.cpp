class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int i = 0,j=m-1;
        int ans = 0;
        while(i<n && j>=0)
        {
            if(grid[i][j]<0)
            {
                j--;
            }
            else{
                ans+=(m-j-1);
                i++;
            }
        }
        if(j==-1)
        {
            int rem = n-i-1;
            ans+=m;
            ans+=m*rem;
        }
        return ans;
    }
};
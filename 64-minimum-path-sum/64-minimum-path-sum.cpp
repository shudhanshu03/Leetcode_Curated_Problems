class Solution {
public:
    
    int helper(int m , int n , vector<vector<int>>&grid , vector<vector<int>>&dp)
    {
        if(m==0 && n==0)
        {
            return grid[m][n];
        }
        if(m<0 || n<0)
        {
            return INT_MAX;
        }
        if(dp[m][n]!=-1)
        {
            return dp[m][n];
        }
        int left = helper(m,n-1,grid,dp);
        int up = helper(m-1,n,grid,dp);
        return dp[m][n] = grid[m][n] + min(left,up);
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        
        return helper(m-1,n-1,grid,dp);
        
    }
};
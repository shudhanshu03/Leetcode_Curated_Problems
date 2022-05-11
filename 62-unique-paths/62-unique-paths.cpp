class Solution {
public:
    int up(int i,int j, int m ,int n,vector<vector<int>>&dp)
    {
        if(i>=m || j>=n)
        {
            return 0;
        }
        else if(i==m-1 && j==n-1)
        {
            return 1;
        }
        else if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        else{
            return dp[i][j] = up(i+1,j,m,n,dp)+up(i,j+1,m,n,dp);
        }
    }
    
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        
        int res = up(0,0,m,n,dp);   
        
        return res;
    }
};
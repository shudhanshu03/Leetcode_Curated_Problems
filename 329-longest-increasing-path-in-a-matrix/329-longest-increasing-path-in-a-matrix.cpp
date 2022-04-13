class Solution {
public:
    
    vector<vector<int>>dir={{0,1},{0,-1},{1,0},{-1,0}};
    
    int dfs(int i , int j , int n, int m ,vector<vector<int>>&matrix, int prev,vector<vector<int>>&dp)
    {
        if(i<0 || i==n || j<0 || j==m || prev>=matrix[i][j])
        {
            return 0;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        
        int cnt = 0;
        
        for(auto di:dir)
        {
            cnt = max(cnt,dfs(di[0]+i,di[1]+j,n,m,matrix,matrix[i][j],dp));
        }
        
        return dp[i][j]=max(cnt+1,dp[i][j]);
        
        
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        int res=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                
                    int c = dfs(i,j,n,m,matrix,-1,dp);
                    res=max(res,c);
                
            }
        }
        return res;
    }
};
class Solution {
public:
    
    int help(int i , int j , vector<vector<int>>&triangle , vector<vector<int>>&dp)
    {
        if(i>=triangle.size())
        {
            return 0;
        }
        
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        
        int down = help(i+1,j,triangle,dp);
        int diag = help(i+1,j+1,triangle,dp);
        
        return dp[i][j] = triangle[i][j] + min(down,diag);
        
        
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>>dp(201,vector<int>(201,-1));
        return help(0,0,triangle,dp);
    }
};
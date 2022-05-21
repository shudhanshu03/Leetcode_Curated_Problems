class Solution {
public:
    
    int help(int n, int m, string &text1 , string &text2 , vector<vector<int>>&dp)
    {
        if(n<0 || m<0)
        {
            return 0;
        }
        
        if(dp[n][m]!=-1)
        {
            return dp[n][m];
        }
        
        if(text1[n]==text2[m])
        {
            return dp[n][m] = 1+help(n-1,m-1,text1,text2,dp);
        }
        else{
            return dp[n][m]=max(help(n-1,m,text1,text2,dp),help(n,m-1,text1,text2,dp));
        }
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return help(n-1,m-1,text1,text2,dp);
    }
};
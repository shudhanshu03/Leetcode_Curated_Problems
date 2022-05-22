class Solution {
public:
    
    int help(int n, int m , string &s1 , string &s2 , vector<vector<int>>&dp)
    {
        if(n<0 || m<0)
        {
            return 0;
        }
        if(dp[n][m]!=-1)
        {
            return dp[n][m];
        }
        if(s1[n]==s2[m])
        {
            return dp[n][m] = 1+help(n-1,m-1,s1,s2,dp);
        }
        else{
            return dp[n][m] = max(help(n-1,m,s1,s2,dp),help(n,m-1,s1,s2,dp));
        }
    }
    
    int longestPalindromeSubseq(string s) {
        string s1 = s;
        string s2 = s1;
        reverse(s2.begin(),s2.end()); // Key Step
        int n = s1.length();
        int m = s2.length();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return help(n-1,m-1,s1,s2,dp);
        
    }
};
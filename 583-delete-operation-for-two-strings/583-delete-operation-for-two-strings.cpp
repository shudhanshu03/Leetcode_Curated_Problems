class Solution {
public:
    
    int help(int n, int m , string &word1 , string& word2 , vector<vector<int>>&dp)
    {
        if(n<0 || m<0)
        {
            return 0;
        }
        if(dp[n][m]!=-1)
        {
            return dp[n][m];
        }
        if(word1[n]==word2[m])
        {
            return dp[n][m] = 1+help(n-1,m-1,word1,word2,dp);
        }
        else{
            return dp[n][m] = max(help(n,m-1,word1,word2,dp),help(n-1,m,word1,word2,dp));
        }
    }
    
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        
        vector<vector<int>>dp(n,vector<int>(m,-1));
        
        int del = help(n-1,m-1,word1,word2,dp);
        
        int delreq = n-del;
        
        if(del==m)
        {
            return delreq;
        }
        return delreq + (m-del);
        
        
    }
};
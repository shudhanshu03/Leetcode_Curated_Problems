class Solution {
public:
    bool recursion(string s1, int i,string s2,int j ,string s3 ,int k,vector<vector<int>>&dp)
    {
        if(i==s1.length() && j==s2.length() && k==s3.length())
            return true; // when all three strings reach end simultaneously 
        
        if(k==s3.length()) return false; 
        if(dp[i][j]!=-1) return dp[i][j];
        
    
        if(s1[i]==s3[k] && recursion(s1,i+1,s2,j,s3,k+1,dp))
            return dp[i][j]=true;
        if(s2[j]==s3[k] && recursion(s1,i,s2,j+1,s3,k+1,dp))
            return dp[i][j]=true;
        
        return dp[i][j]=false;
    }
  
    bool isInterleave(string s1, string s2, string s3) 
    {
        if(s1.length()+s2.length()!=s3.length())
            return false;
            
        vector<vector<int>>dp(s1.length()+1,vector<int>(s2.length()+1,-1));
        
        return recursion(s1,0,s2,0,s3,0,dp);
    }
};
class Solution {
public:
    
    int helper(int i,int j,string &s,vector<vector<int>>&dp)
    {
        if(i>=j)
        {
            return 1;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        
        if(s[i]==s[j])
        {
            return dp[i][j] = helper(i+1,j-1,s,dp);
        }
        else{
            return dp[i][j] = 0;
        }
    }
    int countSubstrings(string s) {
        
        vector<vector<int>>dp(s.size(),vector<int>(s.size(),-1));
        int count = 0;
        for(int i=0;i<s.size();i++)
        {
            for(int j=i;j<s.size();j++)
            {
                count+=helper(i,j,s,dp);
            }
        }
        return count;
        
        
    }
};
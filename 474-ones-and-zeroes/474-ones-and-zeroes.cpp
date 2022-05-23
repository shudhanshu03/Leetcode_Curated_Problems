class Solution {
public:
    int func(vector<string> &str , int m , int n , vector<vector<vector<int>>> &dp , int index)
    {
        if(index>=str.size())
        {
            return 0;
        }
        if(m==0 && n==0)
        {
            return 0;
        }
        
       
        if(dp[m][n][index]!=-1)
        {
            return dp[m][n][index];
        }
        
        int c0 =0 , c1=0;
        
        for(int i=0;i<str[index].size();i++)
        {
            if(str[index][i]=='0')
            {
                c0++;
            }
            else
            {
                c1++;
            }
        }
        
        int v1=0 , v2=0;
        if(c0<=m && c1<=n)
         v1 = 1 + func(str , m-c0 , n-c1 , dp , index+1);
        
         v2 = func(str , m  , n , dp , index+1);
        
        return dp[m][n][index] = max(v1 , v2);
    }
    int findMaxForm(vector<string>& str, int m, int n) {
        
       int p=str.size();
        
        vector<vector<vector<int>>> dp(m+1 , vector<vector<int>>(n+1 , vector<int>(p, -1)));
        
        
        return func(str , m , n , dp , 0);
        
    }
};

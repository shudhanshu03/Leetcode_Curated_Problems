class Solution {
public:
    int fill(int ss,vector<vector<int>>&g , vector<int>&s)
    {
        int ans = 1;
        
        for(auto i:g[ss])
        {
            ans+=fill(i,g,s);
        }
        return s[ss]=ans;
    }
    
    
    int countHighestScoreNodes(vector<int>& parents) {
        int n = parents.size();
        vector<vector<int>>g(n);
        
        vector<int>s(n,0);
        
        for(int i=1;i<n;i++)
        {
            g[parents[i]].push_back(i);
        }
        fill(0,g,s);
        long long maxs = 1;
        long long maxc = 0;
        
        for(int i=0;i<n;i++)
        {
            long long product = 1;
            product = max(product,(long long)(n-s[i]));
            
            for(auto ii:g[i])
            {
                product = product*s[ii];
            }
            
            if(product > maxs)
            {
                maxs = product;
                maxc=1;
            }
            else if(product==maxs)
            {
                maxc++;
            }
        }
        return maxc;
    }
};
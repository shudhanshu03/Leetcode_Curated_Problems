class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int>o(n,0);
        vector<int>ii(n,0);
        
        for(int i=0;i<trust.size();i++)
        {
            o[trust[i][0]-1]++;
            ii[trust[i][1]-1]++;
        }
        
        for(int i=0;i<n;i++)
        {
            if(ii[i]==n-1 && o[i]==0)
            {
                return i+1;
            }
        }
        return -1;
    }
};
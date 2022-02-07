class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int>id(n+1,0);
        vector<int>od(n+1,0);
        
        for(int i=0;i<trust.size();i++)
        {
            od[trust[i][0]]++;
            id[trust[i][1]]++;
        }
        
        for(int i=1;i<=n;i++){
            if(od[i]==0 && id[i]==n-1)
            {
                return i;
            }
        }
       return -1; 
    }
};
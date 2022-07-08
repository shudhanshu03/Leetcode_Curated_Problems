class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int res=0;
        int n = time.size();
        vector<int>div(60,0);
        
        for(int i=0;i<n;i++)
        {
            int c = time[i]%60;
            if(c==0)
            {
                res+=div[0];
            }
            else{
                res+=div[60-c];
            }
            div[c]++;
            
        }
        return res;
        
        
    }
};
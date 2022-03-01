class Solution {
public:
    
    int cb(int a)
    {
        int r = 0;
        while(a!=0)
        {
            if(a%2!=0)
            {
                r++;
            }
            a=a/2;
        }
        return r;
    }
    
    vector<int> countBits(int n) {
        
        vector<int>res(n+1);
        for(int i=0;i<=n;i++)
        {
              res[i] = cb(i);    
        }
        return res;
    }
};
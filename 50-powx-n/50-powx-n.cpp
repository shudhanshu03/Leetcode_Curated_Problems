class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1.0;
        bool flag = 0;
        if(n<0)
        {
            n = abs(n);
            flag = 1;
        }
        
        long long q = n;
        
        while(q)
        {
            if(q%2==0)
            {
                x = x*x;
                q = q>>1;
            }
            else{
                ans = ans*x;
                q--;
            }
        }
        
        if(flag)
        {
            ans = (double)(1.0)/(double)(ans);
        }
        return ans;
    }
};
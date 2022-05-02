class Solution {
public:
    int mySqrt(int x) {
        long long int i = 1,j=x;
        int ans = 0;
        while(i<=j)
        {
            long long int res = i*i;
            if(res==x)
            {
                return i;
            }
            else if(res<x)
            {
                ans = i;
                i++;
            }
            else{
                break;
            }
        }
        return ans;
    }
};
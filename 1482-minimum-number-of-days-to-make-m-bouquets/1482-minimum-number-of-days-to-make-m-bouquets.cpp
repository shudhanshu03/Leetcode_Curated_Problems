class Solution {
public:
    bool isValid(vector<int>&bloomDay,int mid , int k,int m)
    {
        int c = 0;
        int suba = 0;
        
        for(int i=0;i<bloomDay.size();i++)
        {
            if(bloomDay[i]<=mid)
            {
                c++;
                if(c==k)
                 {
                   suba++;
                    c=0;
                 }
            }
            else{
                c=0;
            }
            
            
        }
        return suba>=m;
    }
    
    int minDays(vector<int>& bloomDay, int m, int k) {
        int l=INT_MAX;
        int h=INT_MIN;
        int n = bloomDay.size();
        
        if(m*k>n)
        {
            return -1;
        }
        for(int i=0;i<n;i++)
        {
            l = min(l,bloomDay[i]);
            h = max(h,bloomDay[i]);
        }
        int res;
        while(l<h)
        {
            int mid = l+(h-l)/2;
            
            if(isValid(bloomDay,mid,k,m))
            {
                h = mid;
            }
            else{
                l = mid+1;
            }
        }
        return l;
    }
};
class Solution {
public:
    bool isValid(vector<int>&weights,int days , int cap)
    {
        int s = 0;
        int c = 1;
        
        for(auto i:weights)
        {
            s+=i;
            if(s>cap)
            {
                c++;
                s = i;
            }
            if(c>days)
            {
                return false;
            }
        }
        return true;
    }
    
    int shipWithinDays(vector<int>& weights, int days) {
        int l = INT_MIN;
        int h = 0;
        
        for(int i=0;i<weights.size();i++)
        {
            l = max(l,weights[i]);
            h+=weights[i];
        }
        int res;
        while(l<=h)
        {
            int mid = (l+h)>>1;
            
            if(isValid(weights,days,mid))
            {
                res = mid;
                h = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return res;
        
    }
};
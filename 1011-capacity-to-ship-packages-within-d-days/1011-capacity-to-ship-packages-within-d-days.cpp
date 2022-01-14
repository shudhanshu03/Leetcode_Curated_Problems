class Solution {
public:
    
    bool isOk(vector<int>&weights, int days , int tres)
    {
        int sum = 0;
        int c = 1;
        
        for(auto i:weights)
        {
            sum+=i;
            
            if(sum > tres)
            {
                sum = i;
                c++;
                
            }
            if(c > days)
            {
                return false;
            }
            
        }
        return true;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int s = 0;
        int mind = INT_MIN;
        for(auto i:weights)
        {
            s+=i;
            mind = max(mind,i);
        }
        int l = mind;
        int h = s;
        int res;
        while(l<=h)
        {
            int acceptedDays = (l+h) >> 1;
            
            if(isOk(weights,days,acceptedDays))
            {
                res = acceptedDays;
                h = acceptedDays-1;
            }
            else{
                l = acceptedDays+1;
            }
        }
        return res;
    }
};
class Solution {
public:
    bool isValid(vector<int>&nums , int mid , int m)
    {
        int s = 0;
        int c = 1;
        
        for(auto i:nums)
        {
            s+=i;
            if(s>mid)
            {
                s=i;
                c++;
            }
            if(c>m)
            {
                return false;
            }
        }
        return true;
    }
    
    int splitArray(vector<int>& nums, int m) {
        int l = INT_MIN;
        int h = 0;
        
        for(int i=0;i<nums.size();i++)
        {
            l = max(l,nums[i]);
            h+=nums[i];
        }
        int res;
        while(l<=h)
        {
            int mid = l+(h-l)/2;
            
            if(isValid(nums,mid,m))
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
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = 0,h=nums.size()-1;
        vector<int>res(2,-1);
        while(l<=h)
        {
            int mid = l+(h-l)/2;
            
            if(nums[mid]==target)
            {
                if(mid==l || nums[mid]!=nums[mid-1])
                {
                    res[0]=mid;
                    break;
                }
                else{
                    h = mid-1;
                    res[0]=mid-1;
                }
            }
            else if(nums[mid]<target)
            {
                l = mid+1;
            }
            else{
                h = mid-1;
            }
        }
        
        l=0,h=nums.size()-1;
        
        while(l<=h)
        {
            int mid = l+(h-l)/2;
            
            if(nums[mid]==target)
            {
                if(mid==h || nums[mid]!=nums[mid+1])
                {
                    res[1]=mid;
                    
                    break;
                }
                else{
                    res[1]=mid+1;
                    l = mid+1;
                }
            }
            else if(nums[mid]<target)
            {
                l = mid+1;
            }
            else{
                h = mid-1;
            }
        }
        return res;
    }
};
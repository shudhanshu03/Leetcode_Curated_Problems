class Solution {
public:
    
    bool check(int mid , vector<int>&nums , int maxOperations)
    {
        int c = 0;
        
        for(auto i:nums)
        {
            c+=i/mid - (i%mid==0);
        }
        return c<=maxOperations;
    }
    
    int minimumSize(vector<int>& nums, int maxOperations) {
        int ans = 0;
        int l = 1;
        int h = *max_element(nums.begin(),nums.end());
        
        while(l<=h)
        {
            int mid = l + (h-l)/2;
            
            if(check(mid,nums,maxOperations))
            {
                ans = mid;
                h = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return ans;
    }
};
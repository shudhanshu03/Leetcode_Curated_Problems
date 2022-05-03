class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0,h=nums.size()-1;
        
        while(l<h)
        {
            int mid = (l+h)/2;
            
            if(nums[l]<nums[h])
            {
                return nums[l];
            }
            else if(nums[mid]>=nums[l])
            {
                l = mid+1;
            }
            else{
                h = mid;
            }
        }
        return nums[l];
    }
};
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int minp = 1;
        int maxp = 1;
        int res = INT_MIN;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<0)
            {
                swap(minp,maxp);
            }
            
            minp = min(minp*nums[i],nums[i]);
            maxp = max(maxp*nums[i],nums[i]);
            
            res = max(res,maxp);
        }
        return res;
    }
};
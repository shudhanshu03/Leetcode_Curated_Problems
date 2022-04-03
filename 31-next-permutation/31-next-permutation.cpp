class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int bp = -1;
        int n = nums.size();
        for(int i=n-2;i>=0;i--)
        {
            if(nums[i]<nums[i+1])
            {
                bp=i;
                break;
            }
        }
        if(bp==-1)
        {
            reverse(nums.begin(),nums.end());
        }
        else{
            int index;
            for(int i=n-1;i>bp;i--)
            {
                if(nums[i]>nums[bp])
                {
                    index = i;
                    break;
                }
            }
            swap(nums[bp],nums[index]);
            reverse(nums.begin()+bp+1,nums.end());
        }   
        
    }
};
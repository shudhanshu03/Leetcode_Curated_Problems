class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int me = 0;
        int count = 1;
        int n = nums.size();
        for(int i=1;i<n;i++)
        {
            if(nums[i]==nums[me])
            {
               count++;
            }
            else{
                count--;
                if(count==0)
                {
                    me = i;
                    count = 1;
                }
            }
        }
        return nums[me];
    }
};
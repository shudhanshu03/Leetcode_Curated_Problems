class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        if(nums.empty())
        {
            return 0;
        }
        sort(nums.begin(),nums.end());
        
        int c = 1;
        int res =1;
        for(int i=1;i<nums.size();i++)
        {
            if((nums[i] - nums[i-1]) == 1)
            {
                c++;
            }
            else if(nums[i]==nums[i-1])
            {
                continue;
            }
            else{
                res = max(res,c);
                c=1;
            }
        }
        return res > c ? res:c;
        
        
        
    }
};
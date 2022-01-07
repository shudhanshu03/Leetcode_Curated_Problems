class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int res = 0,c=0;
        int m = 1;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==m)
            {
                c++;
            }
            else{
                res = max(res,c);
                c=0;
            }
        }
        return res > c ? res:c;
    }
};
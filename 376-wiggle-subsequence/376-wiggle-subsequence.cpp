class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int res = 0;
        if(nums.size()==1)
        {
            return 1;
        }
        int prevd = nums[1]-nums[0];
        
        if(prevd==0)
        {
            res = 1;
        }
        else{
            res = 2;
        }
        
        for(int i=2;i<nums.size();i++)
        {
            int currd = nums[i]-nums[i-1];
            if((prevd<=0 && currd>0) || (prevd>=0 && currd<0))
            {
                prevd = currd;
                res++;
            }
        }
        return res;
        
    }
};
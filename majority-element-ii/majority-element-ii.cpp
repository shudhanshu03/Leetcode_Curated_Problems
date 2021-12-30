class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
         
        
        int c1=0,c2=0;
        int me1 = -1,me2=-1;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==me1)
            {
                c1++;
            }
            else if(nums[i]==me2)
            {
                c2++;
            }
            else if(c1==0)
            {
                me1 = nums[i];
                c1=1;
            }
            else if(c2==0)
            {
                me2 = nums[i];
                c2=1;
            }
            else{
                c1--;
                c2--;
            }
        }
        
        vector<int>res;
        int c = 0,cc=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==me1)
            {
                c++;
            }
            else if(nums[i]==me2)
            {
                cc++;
            }
        }
        if(c>nums.size()/3)
        {
            res.push_back(me1);
        }

        if(cc>nums.size()/3)
        {
            res.push_back(me2);
        }
        
        return res;
        
        
    }
};
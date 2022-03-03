class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        vector<int>res;
        int n = nums.size();
        if(nums.size()<3)
        {
            return 0;
        }
        for(int i=1;i<n;i++)
        {
            res.push_back(nums[i]-nums[i-1]);
        }
        
        int c = 0;
        int dv=res[0];
        int ans = 0;
        int v = 2;
        for(int i=1;i<res.size();i++)
        {
            if(res[i]==dv)
            {
                if(c>0)
                {
                    c+=v;
                    v++;
                }
                else{
                    c++;
                }
            }
            else{
                dv = res[i];
                ans+=c;
                c=0;
                v=2;
            }
        }
        if(ans)
        {
            return ans+c;
        }
        else{
            return c;
        }
        
    }
};
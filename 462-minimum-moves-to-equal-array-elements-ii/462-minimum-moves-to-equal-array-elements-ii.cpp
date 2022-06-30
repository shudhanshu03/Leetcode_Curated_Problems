class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n  = nums.size();
        int res = 0;
        sort(nums.begin(),nums.end());           
        if(n%2!=0)
        {
            int q = nums[n/2];
            for(int i=0;i<n;i++)
            {
                res = res + abs(nums[i]-q);
            }
        }
        else{
            int q1 = nums[n/2];
            int lefti = n/2 - 1;
            int q2 = nums[lefti];
            int res1 = 0;
            int res2=0;
            
            for(int i=0;i<n;i++)
            {
                res1 = res1+abs(nums[i]-q2);
            }
            for(int i=0;i<n;i++)
            {
                
                res2 = res2+abs(nums[i]-q1);
            }
            res = min(res1,res2);
        }
        
        return res;
    }
};
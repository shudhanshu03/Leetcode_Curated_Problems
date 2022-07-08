class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int cmin = INT_MAX;
        int res = cmin;
        
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int i=0;
        
        while(i<n-2)
        {
            int j = i+1;
            int k = n-1;
            while(j<k)
            {
               int s = nums[i]+nums[j]+nums[k];
               
               if(abs(target-s)<cmin)
               {
                   cmin = abs(target-s);
                   res = s;
               }
               if(s==target)
               {
                   return s;
               }
               if(s>target)
               {
                   k--;
               }
                else{
                    j++;
                }
                
            }
            i++;
        }
        return res;
    }
};
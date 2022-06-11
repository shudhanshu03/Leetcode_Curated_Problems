class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        
        unordered_map<int,int>m;
        
        m[0]=0;
        
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            m[sum] = i;
        }
        
        if(x > sum)
        {
            return -1;
        }
        int l = 0;
        int cs = 0;
        sum = sum-x;
        for(int i=0;i<n;i++)
        {
            cs+=nums[i];
            
            if(m.find(cs-sum)!=m.end())
            {
               if(cs-sum==0)
               {
                   l = max(l,i-m[cs-sum]+1);
               }
                else{
                    l = max(l,i-m[cs-sum]);
                }
            }
        }
        
        if(l==0)
        {
            if(sum==0)
            {
                return n;
            }
            else{
                return -1;
            }
            
        }
        return n-l;
    }
};
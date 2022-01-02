class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
       unordered_map<int,int>m;
        m[0]=1;
        int ps = 0;
        int c = 0;
        for(int i=0;i<nums.size();i++)
        {
            ps+=nums[i];
            
            if(m.find(ps-k)!=m.end())
            {
               c+=m[ps-k];
                
            }
            m[ps]++;
            
            
        }
        return c;
    }
};
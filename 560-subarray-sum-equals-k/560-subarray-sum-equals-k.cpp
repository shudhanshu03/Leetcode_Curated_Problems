class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>m;
        m[0]=1;
        int cs=0;
        int res=0;
        for(int i=0;i<nums.size();i++)
        {
            cs+=nums[i];
            
            if(m.find(cs-k)!=m.end())
            {
                res+=m[cs-k];
            }
            m[cs]++;
        }
        return res;
    }
};
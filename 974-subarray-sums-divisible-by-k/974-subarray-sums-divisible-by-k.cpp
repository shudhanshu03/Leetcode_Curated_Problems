class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int>m;
        int s=0;
        int r=0;
        int res=0;
        for(int i=0;i<nums.size();i++)
        {
            s+=nums[i];
            r = s%k;
            
            if(r<0)
            {
                r = r+k;
            }
            if(r==0)
            {
                res++;
            }
            if(m.find(r)!=m.end())
            {
                res = res+m[r];
                m[r]++;
            }
            else{
                m[r]++;
            }
        }
        return res;
    }
};
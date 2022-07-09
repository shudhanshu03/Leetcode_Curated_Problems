class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        set<int>s;
        map<int,int>m;
        for(int i=0;i<nums.size();i++)
        {
            s.insert(nums[i]);
            m[nums[i]]++;
        }
        
        int res=0;
        if(k==0)
        {
            for(auto i:m)
            {
                if(i.second>=2)
                {
                    res++;
                }
            }
        }
        else{
            for(auto i:s)
        {
            if(s.find(k+i)!=s.end())
            {
                res++;
            }
        }
        }
        
        return res;
    }
};
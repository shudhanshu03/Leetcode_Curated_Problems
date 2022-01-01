class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>>res;
        int n = nums.size();
        if(n<4)
        {
            return {};
        }
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-3;i++)
        {
            for(int j=i+1;j<n-2;j++)
            {
                int l = j+1;
                int r = n-1;
                int targett = target - nums[i]-nums[j];
                while(l<r)
                {
                    long long int sum = nums[l]+nums[r];
                    if(sum>targett)
                    {
                        r--;
                    }
                    else if(sum<targett)
                    {
                        l++;
                    }
                    else{
                        res.push_back({nums[i],nums[j],nums[l],nums[r]});
                        int ll = nums[l];
                        int rr = nums[r];
                        while(l<r && nums[l]==ll)
                        {
                            l++;
                        }
                        while(r>l && nums[r]==rr)
                        {
                            r--;
                        }
                    }
                    
                }
                while(j+1<n-2 && nums[j]==nums[j+1])
                {
                    j++;
                }
            }
            while(i+1<n-3 && nums[i]==nums[i+1])
            {
                i++;
            }
        }
        return res;
    }
};
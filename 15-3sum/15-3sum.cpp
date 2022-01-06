class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>>v;
        if(n<3)
        {
            return {};
        }
        
        for(int i=0;i<n-2;i++)
        {
            int l = i+1;
            int r = n-1;
            int target = -nums[i];
            while(l<r)
            {
                long long int sum = nums[l]+nums[r];
                
                if(sum < target)
                {
                    l++;
                }
                else if(sum> target)
                {
                    r--;
                }
                else{
                    v.push_back({nums[i],nums[l],nums[r]});
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
            while(i<n-2 && nums[i]==nums[i+1])
            {
                i++;
            }
        }
        return v;
    }
};
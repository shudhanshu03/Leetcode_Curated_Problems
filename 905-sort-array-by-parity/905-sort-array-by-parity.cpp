class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int i=0;
        int j=nums.size()-1;
        vector<int>v;
        while(i<j)
        {
            if(nums[i]%2==0)
            {
                v.push_back(nums[i]);
                i++;
            }
            else if(nums[i]%2!=0)
            {
                swap(nums[i],nums[j]);
                j--;
            }
            
        }
        
        j=nums.size()-1;
        while(i<=j)
        {
            v.push_back(nums[i]);
            i++;
        }
        return v;
    }
};
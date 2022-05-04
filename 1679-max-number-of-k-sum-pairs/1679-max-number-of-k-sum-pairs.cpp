class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int i=0,j=n-1;
        int c = 0;
        while(i<j)
        {
            if(nums[j]+nums[i]==k)
            {
                c++;
                i++;
                j--;
            }
            else if(nums[i]+nums[j]<k)
            {
                i++;
            }
            else{
                j--;
            }
        }
        return c;
        
    }
};
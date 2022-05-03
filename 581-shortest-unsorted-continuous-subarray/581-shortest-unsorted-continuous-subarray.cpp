class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<int>v(nums);
        
        sort(v.begin(),v.end());
        
        int i=0,j=n-1;
        
        while(i<n && nums[i]==v[i])
        {
                i++;
            
        }
        while(j>i && nums[j]==v[j])
        {
            j--;
        }
        
       return j-i+1; 
        
    }
};
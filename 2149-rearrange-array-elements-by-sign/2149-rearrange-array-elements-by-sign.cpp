class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        
        vector<int>res(n);
        int negi=1;
        int posi=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]>=0)
            {
                res[posi]=nums[i];
                posi=posi+2;
            }
            else{
                res[negi]=nums[i];
                negi = negi+2;
            }
        }
        return res;
    }
};
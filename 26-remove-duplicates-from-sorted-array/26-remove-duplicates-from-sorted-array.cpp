class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        /*set<int>s;
        
        for(int i=0;i<nums.size();i++)
        {
            s.insert(nums[i]);
        }
        vector<int>res;
        for(auto i:s)
        {
            res.push_back(i);
        }
        for(int i=0;i<s.size();i++)
        {
            nums[i]=res[i];
        }
        return s.size();
        
        */
        
        // Two Pointer Approach
        int n=nums.size();
         if(n==0){
          return n;
        }
        int i=0,j=1;
        
        while(j<nums.size())
        {
            if(nums[i]!=nums[j])
            {
                i++;
                nums[i]=nums[j];
            }
            j++;
        }
        return i+1;
    }
};
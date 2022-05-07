class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<int>s;
        
        int last = INT_MIN;
        int n = nums.size()-1;
        for(int i=n;i>=0;i--)
        {
            if(nums[i]<last)
            {
                return true;
            }
            
            while(s.empty()==false && nums[i] > s.top())
            {
                last = s.top();
                s.pop();
            }
            
            s.push(nums[i]);
        }
        
        return false;
    }
};
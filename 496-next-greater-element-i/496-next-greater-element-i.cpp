class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        stack<int>s;
        vector<int>res,dum;
        for(auto i:nums2)
        {
            s.push(i);
        }
        
        for(int i=0;i<nums1.size();i++)
        {
            int ans = -1;
              while(s.top()!=nums1[i])
              {
                if(s.top()>nums1[i])
                {
                    ans = s.top(); 
                } 
                dum.push_back(s.top()); 
                s.pop();
              }
            
    
            for(int i=dum.size()-1;i>=0;i--)
            {
                s.push(dum[i]);
            }
            dum.clear();
            res.push_back(ans);       
            
        }
        return res;
    }
};
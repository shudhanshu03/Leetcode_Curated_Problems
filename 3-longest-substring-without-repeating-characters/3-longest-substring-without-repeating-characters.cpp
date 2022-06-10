class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        set<int>ss;
        int res = 0;
        int j = 0;
        for(int i=0;i<s.size();i++)
        {
            if(ss.find(s[i])!=ss.end())
            {
                while(j<i && ss.find(s[i])!=ss.end())
                {
                    ss.erase(s[j]);
                    j++;
                }
            }
            ss.insert(s[i]);
            res = max(res,i-j+1);
            
            
        }
        return res;
        
    }
};
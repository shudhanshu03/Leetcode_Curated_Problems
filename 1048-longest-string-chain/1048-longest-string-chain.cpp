class Solution {
public:
    static bool com(const string &s1, const string &s2) {
        return s1.length() < s2.length();
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),com);
        unordered_map<string,int>m;
        int res = 0;
        for(int i=0;i<words.size();i++)
        {
            m[words[i]]=1;
            for(int j=0;j<words[i].length();j++)
            {
                string prev = words[i].substr(0,j) + words[i].substr(j+1);
                
                if(m.find(prev)!=m.end())
                {
                    m[words[i]] = max(m[words[i]],m[prev]+1);
                }
            }
        }
        for(auto i:m)
        {
         res = max(res,i.second);   
        }
        return res;
        
    }
};
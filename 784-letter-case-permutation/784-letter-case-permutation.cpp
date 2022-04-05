class Solution {
public:
    void helper(int ii , vector<string>&res , string ss, string s)
    {
        if(ss.size()==s.size())
        {
            res.push_back(ss);
            return;
        }
        
        for(int i=ii;i<s.size();i++)
        {
            if(isalpha(s[i]))
            {
                ss.push_back(tolower(s[i]));
                helper(i+1,res,ss,s);
                ss.pop_back();
                ss.push_back(toupper(s[i]));
                helper(i+1,res,ss,s);
                ss.pop_back();
                
            }
            else{
                ss.push_back(s[i]);
                helper(i+1,res,ss,s);
                ss.pop_back();
            }
        }
    }
    
    
    vector<string> letterCasePermutation(string s) {
        vector<string>res;
        string ss="";
        
        helper(0,res,ss,s);
        return res;
    }
};
class Solution {
public:
    vector<string>map = {"abc", "def", "ghi" , "jkl" , "mno" , "pqrs", "tuv" , "wxyz"};
        
    
    void helper(int ii, string &s, vector<string>&res , string digits)
    {
        if(ii==digits.size())
        {
            res.push_back(s);
            return;
        }
        string dum = map[digits[ii]-'2'];
        for(int i=0;i<dum.size();i++)
        {
            s.push_back(dum[i]);
            helper(ii+1,s,res,digits);
            s.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits=="")
        {
            return {};
        }
        vector<string>res;
        string s="";
        helper(0,s,res,digits);
        
        return res;
    }
};
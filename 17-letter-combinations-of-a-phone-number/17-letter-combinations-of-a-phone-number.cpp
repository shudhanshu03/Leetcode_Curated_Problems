class Solution {
public:
    vector<string>dir = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    
    void dfs(int ii,vector<string>&res,string &ans , string &digits)
    {
        if(ii==digits.size())
        {
            res.push_back(ans);
            return;
        }
        
        string dum = dir[digits[ii]-'2'];
        for(int i=0;i<dum.size();i++)
        {
            ans.push_back(dum[i]);
            dfs(ii+1,res,ans,digits);
            ans.pop_back();
        }
        
    }
    
    vector<string> letterCombinations(string digits) {
        vector<string>res;
        if(digits=="")
        {
            return {};
        }
        string ans="";
        dfs(0,res,ans,digits);
        return res;
        
    }
};
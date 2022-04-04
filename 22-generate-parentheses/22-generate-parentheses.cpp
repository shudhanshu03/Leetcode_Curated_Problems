class Solution {
public:
    void helper(int open , int close , int n, string s , vector<string>&res)
    {
        if(s.size()==2*n)
        {
            res.push_back(s);
            return;
        }
        
        if(open < n)
        {
            helper(open+1 , close , n , s+'(',res);
        }
        
        if(close < open)
        {
            helper(open, close+1 , n , s+')',res);
        }
        
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string>res;
        string s;
        
        helper(0,0,n,s,res);
        return res;
    }
};
class Solution {
public:
    bool isValid(string s) {
        
        stack<char>ss;
        
        int n = s.size();
        
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(' || s[i]=='[' || s[i]=='{')
            {
                ss.push(s[i]);
            }
            else{
                if(ss.empty() || ss.top()=='(' && s[i]!=')' || ss.top()=='[' && s[i]!=']' || ss.top()=='{' && s[i]!='}')
                {
                    return false;
                }
                else{
                    ss.pop();
                }
            }
            
        }
        return ss.empty();
    }
};
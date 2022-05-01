class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string temp="";
        string tem = "";
        
        stack<char>s1;
        stack<char>s2;
        
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='#' && s1.empty()==false)
            {
                s1.pop();
            }
            else if(s[i]!='#'){
                s1.push(s[i]);
            }
        }
         for(int i=0;i<t.size();i++)
        {
            if(t[i]=='#' && s2.empty()==false)
            {
                s2.pop();
            }
            else if(t[i]!='#'){
                s2.push(t[i]);
            }
        }
        return s1==s2;
        
        
    }
};
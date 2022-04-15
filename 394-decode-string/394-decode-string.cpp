class Solution {
public:
    string decodeString(string s) {
        stack<char>st;
        
        for(int i=0;i<s.size();i++)
        {
            if(s[i]!=']')
            {
                st.push(s[i]);
            }
            else{
                string temp="";
                
                while(st.top()!='[')
                {
                    temp = st.top() + temp;
                    st.pop();
                }
                st.pop();
                string ss ="";
                
                while(st.empty()==false && isdigit(st.top()))
                {
                    ss = st.top() + ss;
                    st.pop();
                }
                
                int k = stoi(ss);
                while(k--)
                {
                    for(int i=0;i<temp.size();i++)
                    {
                        st.push(temp[i]);
                    }
                }
                
            }
        }
        
        string res="";
        while(st.empty()==false)
        {
            res=st.top()+res;
            st.pop();
        }
        return res;
    }
};
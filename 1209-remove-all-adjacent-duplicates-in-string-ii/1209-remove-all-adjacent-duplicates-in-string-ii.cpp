class Solution {
public:
    string removeDuplicates(string s, int k) {
        // Brute force -> TLE
        /*bool flag = 1;
        while(flag)
        {
            flag = 0;
            int c = 1;
        for(int i=1;i<s.size();i++)
        {
            if(s[i]!=s[i-1])
            {
                c=1;
            }
            else{
                c++;
                if(c==k)
                {
                    s = s.substr(0,i-k+1)+s.substr(i+1);
                    flag = true;
                }
            }
        }
        }
        
        return s;*/
        
        
        // Better Approach
        int n = s.size();
        vector<int>count(n,1);
        stack<int>st;
        st.push(0);
        for(int i=1;i<n;i++)
        {
            if(st.empty()==false)
            {
                if(s[st.top()]==s[i])
                {
                count[i] = count[st.top()]+1;
                }
            }
            
            
            st.push(i);
            
            if(count[st.top()]==k)
            {
                
                for(int i=0;i<k;i++)
                {
                    st.pop();
                }
            }
        }
        
        string res;
        while(st.empty()==false)
        {
            res+=s[st.top()];
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
        
    }
};
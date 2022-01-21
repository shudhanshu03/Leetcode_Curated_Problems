class Solution {
public:
    
    string longestPalindrome(string s) {
        int l,r;
        int n = s.length();
        int si=0,ei=0;
        int ml = 1;
        
        if(n<=1)
        {
            return s;
        }
        for(int i=0;i<n-1;i++)
        {
            l=i,r=i;
            while(l>=0 && r<n)
            {
                if(s[l]==s[r])
                {
                    l--;
                    r++;
                }
                else{
                    break;
                }
            }
           int len = r-l-1; 
           if(len > ml)
           {
               ml = len;
               si = l+1;
               ei = r-1;
           }
        }
        
        for(int i=0;i<n-1;i++)
        {
            l=i,r=i+1;
            while(l>=0 && r<n)
            {
                if(s[l]==s[r])
                {
                    l--;
                    r++;
                }
                else{
                    break;
                }
            }
           int len = r-l-1; 
           if(len > ml)
           {
               ml = len;
               si = l+1;
               ei = r-1;
           }
        }
        
        return s.substr(si,ml);
        
    }
};
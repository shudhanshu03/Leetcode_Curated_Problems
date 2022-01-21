class Solution {
public:
    string reverseWords(string s) {
        string res="";
        
        int i = 0,j;
        int n = s.length();
        
        while(i<n)
        {
            while(s[i]==' ')
            {
                i++;
            }
            
            if(i>=n)
            {
                break;
            }
            j = i;
            
            while(j<n && s[j]!=' ')
            {
                j++;
            }
            string ans = s.substr(i,j-i);
            
            if(res=="")
            {
                res  = ans;
            }
            else{
                res = ans + " " + res;
            }
            i = j;
        }
        return res;
    }
};
class Solution {
public:
    bool validPalindrome(string s) {
        int i=0;
        int j=s.length()-1;
        
        while(i<j)
        {
            if(s[i]!=s[j])
            {
                int i1 = i,j1=j-1;
                int i2 = i+1,j2=j;
        
                 while(i1<j1 && s[i1]==s[j1])
                {
                 i1++;
                 j1--;
            
                 }
                 while(i2<j2 && s[i2]==s[j2] )
                {
                 i2++;
                 j2--;
                 }
        
               return i1>=j1 || i2>=j2;
            }
          
           i++;
           j--;
        }
       
        return true;
        
    }
};
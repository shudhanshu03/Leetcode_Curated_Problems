class Solution {
public:
    int removePalindromeSub(string s) {
        string ss = s;
        reverse(ss.begin(),ss.end());
        
        if(ss ==s)
        {
            return 1;
        }
        else{
            return 2;
        }
    }
};
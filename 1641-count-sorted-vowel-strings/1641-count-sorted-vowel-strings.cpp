class Solution {
public:
    vector<char>vow = {'a','e','i','o','u'};
    int c = 0;
    void help(string &s,int n,int ind)
    {
        if(s.size()==n)
        {
            c++;
            
            return;
        }
        for(int i=ind;i<vow.size();i++)
        {
            s+=vow[i];
            help(s,n,i);
            s.pop_back();
            
            
        }
    }
    
    int countVowelStrings(int n) {
        string s="";
        help(s,n,0);
        return c;
    }
};
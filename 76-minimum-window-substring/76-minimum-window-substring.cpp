class Solution {
public:
    string minWindow(string s, string t) {
        
        if(t.length()> s.length())
        {
            return "";
        }
        if(s==t)
        {
            return s;
        }
        
        unordered_map<char,int>m;
        
        for(auto i:t)
        {
            m[i]++;
        }
        
        int n = s.size();
        int i=0,j=0;
        int c = m.size();
        int start=-1,end=-1,res=INT_MAX;
        while(j<n)
        {
            if(m.find(s[j])!=m.end())
            {
                m[s[j]]--;
                if(m[s[j]]==0)
                {
                    c--;
                }
            }
            if(c==0)
            {
                if(j-i+1 < res)
                {
                    start = i;
                    end = j;
                    res = j-i+1;
                }
                
                while(c==0)
                {
                    if(m.find(s[i])!=m.end())
                    {
                        if(m[s[i]]==0 || m[s[i]]<0)
                        {
                            m[s[i]]++;
                            if(m[s[i]]>0)
                            {
                                c++;
                            }
                        }
                    }
                    i++;
                    
                    if(j-i+1 < res && c==0)
                    {
                        start = i;
                        end = j;
                        res = j-i+1;
                    }
                }
            }
            j++;
        }
        string ress="";
        if(start==-1 && end==-1)
        {
            return "";
        }
        else{
            for(int i=start;i<=end;i++)
            {
                ress+=s[i];
            }
        }
        return ress;
    }
};
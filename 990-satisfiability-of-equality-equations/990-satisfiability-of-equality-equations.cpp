class Solution {
public:
    int p[26];
    int fp(int x)
    {
        if(x!=p[x])
        {
            p[x] = fp(p[x]);
        }
        return p[x];
    }
    bool equationsPossible(vector<string>& equations) {
        
        for(int i=0;i<26;i++)
        {
            p[i]=i;
        }
        for(auto e:equations)
        {
            if(e[1]=='=')
            {
                p[fp(e[0]-'a')] = fp(e[3]-'a');
            }
        }
        
        for(auto e:equations)
        {
            if(e[1]=='!' && fp(e[0]-'a')==fp(e[3]-'a'))
            {
                return false;
            }
            
        }
        return true;
    }
};
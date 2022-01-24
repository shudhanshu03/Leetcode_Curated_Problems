class Solution {
public:
    string countAndSay(int n) {
        
        if(n==1)
        {
            return "1";
        }
        if(n==2)
        {
            return "11";
        }
        string res = "11";
        for(int i=3;i<=n;i++)
        {
            int c = 1;
            string temp = "";
            int flag = 0;
            for(int i=0;i<res.size()-1;i++)
            {
                if(res[i]==res[i+1])
                {
                    c++;
                }
                else{
                    temp+= to_string(c) + res[i];
                    flag = 1;
                    c=1;
                }
            }
            if(flag)
            {
                temp+= to_string(c) + res[res.size()-1];
            }
            else{
                temp+= to_string(c) + res[0];
            }
            res = temp;
            
        }
        return res;
    }
};
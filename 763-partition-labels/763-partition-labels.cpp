class Solution {
public:
    vector<int> partitionLabels(string s) {
         vector<char>alpha(26,0);
        vector<int>count(26,0);
        
        for(char i:s)
        {
            count[i-97]++;
        }
        
        vector<int>res;
        int l = 0;
        int stillexist = 0;
        
        for(char i:s)
        {
            if(alpha[i-97] == false)
            {
                alpha[i-97] = true;
                stillexist++;
            }
            l++;
            
            count[i-97]--;
            
            if(count[i-97] == 0)
            {
                stillexist--;
                alpha[i-97] = false;
                if(stillexist == 0)
                {
                    res.push_back(l);
                    l=0;
                }
            }
        }
       return res; 
    }
};
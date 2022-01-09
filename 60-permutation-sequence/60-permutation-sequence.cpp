class Solution {
public:
    string getPermutation(int n, int k) {
        int fact =1;
        
        vector<int>factd;
        
        for(int i=1;i<n;i++)
        {
            fact=fact*i;
            factd.push_back(i);
        }
        
        factd.push_back(n);
        
        string ans = "";
        k--;
        
        while(1)
        {
            ans = ans + to_string(factd[k/fact]);
            factd.erase(factd.begin()+k/fact);
            
            if(factd.size()==0)
            {
                break;
            }
            
            k = k%fact;
            fact = fact/factd.size();
        }
        return ans;
    }
};
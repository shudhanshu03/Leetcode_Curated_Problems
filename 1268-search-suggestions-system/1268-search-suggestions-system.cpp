class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
         sort(products.begin(),products.end());
        vector<vector<string>> output;
        vector<string> temp,space,filtered;
        for(int i=0;i<searchWord.size();i++)
        {
            if(i==0)
                space=products;
            else
                space=filtered;
            temp.clear();
            filtered.clear();
            int count=0;
            for(string s:space)
            {
                if(i<s.size() and s[i]==searchWord[i])
                {
                    if(count<3)
                        temp.push_back(s);
                    filtered.push_back(s);
                    count++;
                }
            }
            output.push_back(temp);
        }
        return output;
    }
        
    
};
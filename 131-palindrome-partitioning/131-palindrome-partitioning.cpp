class Solution {
public:
    void helper(int index , string s , vector<string>&temp, vector<vector<string>>&res)
    {
        if(index==s.size())
        {
            res.push_back(temp);
            return;
        }
        
        for(int i=index;i<s.size();i++)
        {
            if(isSafe(s,index,i))
            {
                temp.push_back(s.substr(index,i-index+1));
                helper(i+1,s,temp,res);
                temp.pop_back();
            }
        }
    }
    
    bool isSafe(string s , int start , int end)
    {
        while(start<=end)
        {
            if(s[start]!=s[end])
            {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
    
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>>res;
        vector<string>temp;
        helper(0,s,temp,res);
        
        return res;
    }
};
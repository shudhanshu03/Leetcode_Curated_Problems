class Solution {
public:
    string reorganizeString(string s) {
        map<char,int>m;
        int n = s.size();
        for(int i=0;i<n;i++)
        {
            m[s[i]]++;
        }
        int r = n/2;
        if(n%2!=0)
        {
            r++;
        }
        for(auto it:m)
        {
        
            if(it.second > r)
            {
                return "";
            }
        }
        string res="";
        
        priority_queue<pair<int,char>>pq;
        
        for(auto it:m)
        {
            pq.push({it.second,it.first});
        }
        
        while(pq.size()>1)
        {
            char f = pq.top().second;
            m[f]--;
            pq.pop();
            char s = pq.top().second;
            pq.pop();
            m[s]--;
            
            res = res+f+s;
            if(m[f]>0)
            {
                pq.push({m[f],f});
            }
            if(m[s]>0)
            {
                pq.push({m[s],s});
            }
            
        }
        
        while(pq.empty()==false)
        {
            char f = pq.top().second;
            pq.pop();
            res = res + f; 
        }
        return res;
        
    }
};
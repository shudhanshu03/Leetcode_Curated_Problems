class Solution {
public:
    static int cmp(pair<int,int>&a , pair<int,int>&b)
    {
        if(a.first==b.first)
        {
            return a.second < b.second;
        }
        return a.first < b.first;
    }
    
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<pair<int,int>>v;
        
        for(int i=0;i<arr.size();i++)
        {
            v.push_back({abs(x-arr[i]),arr[i]});
        }
        sort(v.begin(),v.end(),cmp);
        vector<int>res;
        
        for(int i=0;i<k;i++)
        {
            res.push_back(v[i].second);
        }
        sort(res.begin(),res.end());
        return res;
    }
};
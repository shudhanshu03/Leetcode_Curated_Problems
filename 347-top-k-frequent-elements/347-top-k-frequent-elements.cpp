class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>m;
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            m[nums[i]]++;
        }
        vector<int>res;
        priority_queue<pair<int,int>>pq;
        
        for(auto i:m)
        {
            pq.push(make_pair(i.second,i.first));
        }
        
        for(int i=0;i<k;i++)
        {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
        
    }
};
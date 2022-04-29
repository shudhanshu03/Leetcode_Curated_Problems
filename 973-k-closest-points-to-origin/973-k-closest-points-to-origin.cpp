class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        priority_queue<pair<double,int> , vector<pair<double,int>> , greater<pair<double,int>>>pq;
        
        for(int i=0;i<points.size();i++)
        {
            double dist = pow(points[i][0],2) + pow(points[i][1],2);
            dist = sqrt(dist);
            
            pq.push({dist,i});
        }
        vector<vector<int>>res;
        while(k--)
        {
            int index = pq.top().second;
            pq.pop();
            res.push_back(points[index]);
        }
        return res;
        
    }
};
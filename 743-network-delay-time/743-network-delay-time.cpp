class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>>graph[n+1];
        
        for(int i=0;i<times.size();i++)
        {
            graph[times[i][0]].push_back({times[i][1],times[i][2]});
        }
        
        vector<int>dist(n+1,INT_MAX);
        
        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>>pq;
        pq.push({k,0});
        dist[k]=0;
        
        while(pq.empty()==false)
        {
            int node = pq.top().first;
            int dis = pq.top().second;
            pq.pop();
            for(auto q:graph[node])
            {
                int toNode = q.first;
                int disreq = q.second;
                
                if(dist[toNode] > dis + disreq)
                {
                    dist[toNode] = dis + disreq;
                    pq.push({toNode,dist[toNode]});
                }
            }
        }
        
        int res = 0;
        for(int i=1;i<n+1;i++)
        {
            res = max(res,dist[i]);
        }
        
        if(res==INT_MAX)
        {
            return -1;
        }
        return res;
        
    }
};
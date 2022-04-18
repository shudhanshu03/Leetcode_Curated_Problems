class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pair<int,double>>>graph(n);
        vector<double>dist(n,INT_MIN);
        
        for(int i=0;i<edges.size();i++)
        {
            graph[edges[i][0]].push_back({edges[i][1],succProb[i]});
            graph[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }
        
        priority_queue<pair<int,double> , vector<pair<int,double>> , greater<pair<int,double>>>pq;
        pq.push({start,1.0});
        dist[start]=1.0;
        
        while(pq.empty()==false)
        {
            int node = pq.top().first;
            double dis = pq.top().second;
            pq.pop();
            for(auto q:graph[node])
            {
                int toNode = q.first;
                double disreq = q.second;
                
                if(dist[toNode] < disreq*dis)
                {
                    dist[toNode] = disreq*dis;
                    pq.push({toNode,dist[toNode]});
                }
            }
        }
        
        if(dist[end]==INT_MIN)
        {
            return 0.0;
        }
        return dist[end];
    }
};
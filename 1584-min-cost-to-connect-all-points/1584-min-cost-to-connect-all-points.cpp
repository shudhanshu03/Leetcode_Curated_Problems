class Solution {
public:
    
    int find(int a , vector<int>&parent)
    {
        if(parent[a]==a)
        {
            return a;
        }
        return parent[a] = find(parent[a],parent);
    }
    
    void unionn(int a , int b , vector<int>&rank , vector<int>&parent)
    {
        int aa = find(a,parent);
        int bb = find(b,parent);
        
        if(rank[aa]<rank[bb])
        {
            parent[aa]=bb;
        }
        else if(rank[bb]<rank[aa])
        {
            parent[bb]=aa;
        }
        else{
            parent[aa]=bb;
            rank[bb]++;
        }
    }
    
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        
        vector<vector<int>>graph;
        
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int res = abs(points[i][0]-points[j][0]) + abs(points[i][1]-points[j][1]);
                graph.push_back({res,i,j});    
            }
        }
        sort(graph.begin(),graph.end());
        vector<int>parent(n);
        vector<int>rank(n,0);
        
        
        for(int i=0;i<n;i++)
        {
            parent[i]=i;
        }
        int res = 0;
        int c = 0;
        for(auto it:graph)
        {
            if(find(it[1],parent)!=find(it[2],parent))
            {
                c++;
                res+=it[0];
                unionn(it[1],it[2],rank,parent);
                if(c>=n-1)
                {
                    break;
                }
            }
        }
        return res;
        
        
        
    }
};
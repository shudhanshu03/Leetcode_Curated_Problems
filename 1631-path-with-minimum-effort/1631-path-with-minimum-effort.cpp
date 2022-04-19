class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>>dir={{0,-1},{0,1},{-1,0},{1,0}};
        vector<vector<int>>dist(n,vector<int>(m,INT_MAX));
        
        priority_queue<pair<int,pair<int,int>> , vector<pair<int,pair<int,int>>> , greater<pair<int,pair<int,int>>>>pq;
        
        pq.push({0,{0,0}});
        
        while(pq.empty()==false)
        {
            auto it = pq.top();
            pq.pop();
            int d = it.first;
            int row = it.second.first;
            int col = it.second.second;
            if(row==n-1 && col==m-1)
            {
                return d;
            }
            for(auto ii:dir)
            {
                int x = ii[0]+row;
                int y = ii[1]+col;
                
                if(x<0 || x>=n || y<0 || y>=m)
                {
                    continue;
                }
                int res = max(d,abs(heights[x][y]-heights[row][col]));
                if(res < dist[x][y])
                {
                    dist[x][y] = res;
                    pq.push({res,{x,y}});
                }
            }
            
            
        }
        return 0;
        
    }
};
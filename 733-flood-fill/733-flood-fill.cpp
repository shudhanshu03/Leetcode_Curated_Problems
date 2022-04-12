class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int n = image.size();
        int m = image[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,0));
        vis[sr][sc]=1;
        queue<pair<int,int>>q;
        
        q.push({sr,sc});
        
        while(q.empty()==false)
        {
            int r = q.front().first;
            int c = q.front().second;
            
            q.pop();
            
            
            
            if(r-1>=0 && image[r-1][c]==image[r][c] && vis[r-1][c]==0)
            {
                vis[r-1][c]=1;
                q.push({r-1,c});
            }
            if(r+1<n && image[r+1][c]==image[r][c] && vis[r+1][c]==0)
            {
                vis[r+1][c]=1;
                q.push({r+1,c});
            }
            if(c-1>=0 && image[r][c-1]==image[r][c] && vis[r][c-1]==0)
            {
                vis[r][c-1]=1;
                q.push({r,c-1});
            }
            if(c+1<m && image[r][c+1]==image[r][c] && vis[r][c+1]==0)
            {
                vis[r][c+1]=1;
                q.push({r,c+1});
            }
            image[r][c]=newColor;
            
        }
        return image;
    }
};
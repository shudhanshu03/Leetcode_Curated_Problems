class Solution {
public:
    void dfs(int start , int &c , vector<bool>&vis , vector<vector<int>>&stones)
    {
        vis[start] = 1;
        int x = stones[start][0];
        int y = stones[start][1];
        for(int i=0;i<stones.size();i++)
        {
            if(vis[i]==false && (stones[i][0]==x || stones[i][1]==y))
            {
                c++;
                dfs(i,c,vis,stones);
            }
        }
    }
    
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<bool>vis(n,false);
        int c = 0;
        for(int i=0;i<n;i++)
        {
            if(vis[i]==false)
            {
                dfs(i,c,vis,stones);
            }
        }
        return c;
    }
};
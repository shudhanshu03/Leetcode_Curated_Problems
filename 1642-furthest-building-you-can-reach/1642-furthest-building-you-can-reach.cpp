class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int,vector<int>,greater<int>>pq;
        int n = heights.size();
        int s = 0;
        for(int i=1;i<n;i++)
        {
            if(heights[i]>heights[i-1])
            {
                pq.push(heights[i]-heights[i-1]);
                
                if(pq.size()>ladders)
                {
                    s += pq.top();
                    pq.pop();
                }
                
                if(s>bricks)
                {
                    return i-1;
                }
                
                
            }
        }
        return n-1;
    }
};
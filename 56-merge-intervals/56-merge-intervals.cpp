class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        
        vector<vector<int>>res;
        res.push_back(intervals[0]);
        int n = intervals.size();
        int j=0;
        for(int i=1;i<n;i++)
        {
            int prev = res[j][1];
            int next = intervals[i][0];
            
            if(prev>=next)
            {
                res[j][1] = max(prev,intervals[i][1]);
            }
            else{
                res.push_back(intervals[i]);
                j++;
            }
        }
        return res;
        
    }
};
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>res;
        int j = 0;
        int n = intervals.size();
        res.push_back(intervals[0]);
        for(int i=1;i<n;i++)
        {
            int start = res[j][1];
            int end = intervals[i][0];
            if(start >= end)
            {
                res[j][1] = max(start,intervals[i][1]);
            }
            else{
                res.push_back(intervals[i]);
                j++;
            }
        }
        return res;
    }
};
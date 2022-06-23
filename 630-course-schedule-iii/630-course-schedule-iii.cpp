class Solution {
public:
    static bool comparator(const vector<int>& v1, const vector<int>& v2)
    {
        return v1[1] < v2[1];
    }
    
    int scheduleCourse(vector<vector<int>>& courses) {
        
        sort(courses.begin(), courses.end(), comparator);
        
        priority_queue <pair<int, int>> pq;
        
        int days = 0;
        
        for(int i=0; i<courses.size(); i++)
        {
            int dur = courses[i][0];
            int dl = courses[i][1];
            
            pq.push(make_pair(dur, dl));
            
            days = days + dur;
            
            if(days > dl)
            {
                    days = days - pq.top().first;
                    pq.pop();
            }
            
        }
        
        return pq.size();
    
    }
};
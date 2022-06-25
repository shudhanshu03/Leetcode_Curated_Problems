class Solution {
public:
    bool isPossible(vector<int>& target) {
         priority_queue<int> pq;
        long long int sum = 0;
        int n = target.size();
        for(auto x: target)
        {
            sum += x;
            pq.push(x);
        }
        
        while(pq.top()>1)
        {
            sum -= pq.top();
            if(sum>pq.top() || sum==0)
                return false;
            
            
            int a = pq.top()%sum;
            if(a==0 && sum!=1)
                return false;
            
            pq.pop();
            pq.push(a);
            sum += a;
        }
        
        return true;
    }
};
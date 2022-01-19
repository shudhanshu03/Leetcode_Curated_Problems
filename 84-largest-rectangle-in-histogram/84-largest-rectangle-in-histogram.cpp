class Solution {
public:
    
    vector<int>leftsm(vector<int>&heights,int n)
    {
        vector<int>res(n);
        stack<int>s;
        
        for(int i=0;i<n;i++)
        {
            while(s.empty()==false && heights[s.top()]>= heights[i])
            {
                s.pop();
            }
            
            if(s.empty())
            {
                res[i] = -1;
            }
            else{
                res[i] = s.top();
            }
            s.push(i);
        }
        return res;
    }
    
    vector<int>rightsm(vector<int>&heights,int n)
    {
        vector<int>res(n);
        stack<int>s;
        
        for(int i=n-1;i>=0;i--)
        {
            while(s.empty()==false && heights[s.top()]>= heights[i])
            {
                s.pop();
            }
            
            if(s.empty())
            {
                res[i] = -1;
            }
            else{
                res[i] = s.top();
            }
            s.push(i);
        }
        return res;
    }
    
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int>ls(n),rs(n);
        
        ls = leftsm(heights,n);
        rs = rightsm(heights,n);
        int l,r;
        int res = INT_MIN;
        
        for(int i=0;i<n;i++)
        {
            l = ls[i];
            r = rs[i];
            
            if(r==-1)
            {
                r = n;
            }
            int w = r-l-1;
            res = max(res,w*heights[i]);
            
        }
        return res;
        
        
    }
};
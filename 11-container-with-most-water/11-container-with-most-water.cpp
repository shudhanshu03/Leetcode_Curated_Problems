class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0;
        int j = height.size()-1;
        int mh;
        int res = 0;
        while(i<j)
        {
            mh = min(height[i],height[j]);
            res = max(res,(j-i)*mh);
            
            while(mh>=height[i] && i<j)
            {
                i++;
            }
            while(mh>=height[j] && i<j)
            {
                j--;
            }
        }
        return res;
    }
};
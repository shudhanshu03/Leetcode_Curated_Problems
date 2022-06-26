class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int res = 0;
        int n = cardPoints.size();
        for(int i=n-k;i<n;i++)
        {
            res+=cardPoints[i];
        }
        int ans = 0;
        for(int i=0,ans=res;i<k;i++)
        {
            ans = ans-cardPoints[n-k+i];
            ans = ans+cardPoints[i];
            res = max(res,ans);
        }
        return res;
    }
};
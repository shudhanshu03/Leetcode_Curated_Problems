class Solution {
public:
    int minDeletions(string s) {
       vector<int>v(26);
        for(int i = 0; i < s.size(); i++) v[s[i] - 'a']++;
        sort(v.begin(), v.end(), greater<>());
        int ans = 0, freq = v[0];
        for(auto i : v){
            if(i > freq){
                if(freq > 0) ans += (i-freq);
                else ans += i;
            }
            freq = min(freq-1, i-1);
        }
        return ans; 
    }
};
class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
         vector<int> indices;
        vector<int> nSoldiers(mat.size(), 0);
        
        for (int i = 0; i < mat.size(); ++i) {
            for (int j = 0; j < mat[i].size(); ++j) {
                nSoldiers[i] += mat[i][j];
            }
            indices.push_back(i);
        }
        
        stable_sort(indices.begin(), indices.end(), [&](int a, int b){
            return nSoldiers[a] < nSoldiers[b];
        });
            
        return vector<int>(indices.begin(), indices.begin() + k); 
    }
};
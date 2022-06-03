class NumMatrix {
public:
    vector<vector<int>>m;
    NumMatrix(vector<vector<int>>& matrix) {
        m = matrix;
		
        for(int i = 0; i < m.size(); i++)
        {
            for(int j = 0; j < m[0].size(); j++)
            {
                if(i > 0 && j > 0) m[i][j] += m[i][j-1] + m[i-1][j] - m[i-1][j-1];
                else if(i > 0) m[i][j] += m[i-1][j];
                else if(j > 0) m[i][j] += m[i][j-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        if(row1-1 > -1 && col1-1 > -1)
            return m[row2][col2] - m[row1-1][col2] - m[row2][col1-1] + m[row1-1][col1-1];
        if(row1-1 > -1)
            return m[row2][col2] - m[row1-1][col2];
        if(col1-1 > -1)
            return m[row2][col2] - m[row2][col1-1];
        return m[row2][col2];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
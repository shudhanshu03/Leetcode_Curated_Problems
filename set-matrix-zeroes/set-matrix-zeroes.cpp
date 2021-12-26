class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // o(m+n) Approach;
        /*int rows = matrix.size();
        int col = matrix[0].size();
        vector<int>rv(rows,-1),cv(col,-1);
        
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(matrix[i][j]==0)
                {
                    rv[i]=0;
                    cv[j]=0;
                }
            }
        }
        
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(rv[i]==0 || cv[j]==0)
                {
                    matrix[i][j]=0;
                }
            }
        }
       */
        // Optimal Approach - In place space
        int rows = matrix.size();
        int col = matrix[0].size();
        int flag = 0;
        
        for(int i=0;i<rows;i++)
        {
            if(matrix[i][0]==0)
            {
                flag=1;
            }
            for(int j=1;j<col;j++)
            {
                if(matrix[i][j]==0)
                {
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
            }
        }
        
        for(int i=rows-1;i>=0;i--)
        {
            for(int j=col-1;j>=1;j--)
            {
                if(matrix[i][0]==0 || matrix[0][j]==0)
                {
                    matrix[i][j]=0;
                }
            }
            if(flag)
            {
                matrix[i][0]=0;
            }
            
        }
        
    }
};
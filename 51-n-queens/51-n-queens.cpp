class Solution {
public:
    
    bool isSafe(int row , int col , vector<string>&temp , int n )
    {
        int nrow = row;
        int ncol = col;
        
        while(col>=0)
        {
            if(temp[row][col]=='Q')
            {
                return false;
            }
            col--;
        }
        col = ncol;
        
        while(row>=0 && col>=0)
        {
            if(temp[row][col]=='Q')
            {
                return false;
            }
            row--;
            col--;
        }
        row = nrow;
        col = ncol;
        
        while(row<n && col>=0)
        {
            if(temp[row][col]=='Q')
            {
                return false;
            }
            row++;
            col--;
        }
        
        return true;
        
    }
    void helper(int start , vector<string>&temp , vector<vector<string>>&res , int n)
    {
        if(start==n)
        {
            res.push_back(temp);
            return;
        }
        
        for(int i=0;i<n;i++)
        {
            if(isSafe(i,start,temp,n))
            {
                temp[i][start]='Q';
                helper(start+1,temp,res,n);
                temp[i][start]='.';
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>res;
        vector<string>temp(n,string(n,'.'));
        
        helper(0,temp,res,n);
        
        return res;
    }
};
class Solution {
public:
    int c = 0;
    bool isSafe(int row,int col, vector<string>&board,int n)
    {
        int drow = row;
        int dcol = col;
        
        // checking left side in same row
        while(col>=0)
        {
            if(board[row][col]=='Q')
            {
                return false;
            }
            col--;
        }
        
        row = drow;
        col = dcol;
        
        //checking upper left diagonal
        while(row>=0 && col>=0)
        {
            if(board[row][col]=='Q')
            {
                return false;
            }
            row--;
            col--;
        }
        
        //checking bottom left diagonal
        
        row = drow;
        col = dcol;
        
        while(row<n && col>=0)
        {
            if(board[row][col]=='Q')
            {
                return false;
            }
            row++;
            col--;
        }
        
        return true;
        
    }
    void solve(int col , vector<string>&board,vector<vector<string>>&res,int n)
    {
        if(col == n)
        {
            res.push_back(board);
            c++;
            return;
        }
        
        for(int i=0;i<n;i++)
        {
            if(isSafe(i,col,board,n))
            {
                board[i][col] = 'Q';
                solve(col+1,board,res,n);
                board[i][col]='.';
            }
        }
    }
    
    int totalNQueens(int n) {
        vector<vector<string>>res;
        vector<string>board(n,string(n,'.'));
        
        solve(0,board,res,n);
        return c;
    }
};
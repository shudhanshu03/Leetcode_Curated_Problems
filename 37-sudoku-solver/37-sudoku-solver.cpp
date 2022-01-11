class Solution {
public:
    
    bool solve(vector<vector<char>>&board)
    {
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(board[i][j]=='.')
                {
                    for(char c = '1';c<='9';c++)
                    {
                         if(isSafe(board,i,j,c))
                         {
                             board[i][j] = c;
                             
                             if(solve(board))
                             {
                                 return true;
                             }
                             else{
                                 board[i][j]='.';
                             }
                         }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    
    bool isSafe(vector<vector<char>>&board,int r,int c,char cc)
    {
        for(int i=0;i<9;i++)
        {
            if(board[i][c]==cc)
            {
                return false;
            }
            if(board[r][i]==cc)
            {
                return false;
            }
            
            if(board[3*(r/3)+i/3][3*(c/3)+i%3]==cc)
            {
                return false;
            }
        }
        return true;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }

};
class Solution {
public:
    int neighbors(int i,int j,vector<vector<int>>& board,int n,int m)
{
int count=0;
if(i-1>=0 && j<m && board[i-1][j]==1)
count++;
if(i-1>=0 && j-1>=0 && board[i-1][j-1]==1)
count++;
if(j-1>=0 && board[i][j-1]==1)
count++;
if(i+1<n && j-1>=0 && board[i+1][j-1]==1)
count++;
if( i+1<n && board[i+1][j]==1)
count++;
if(i+1<n && j+1<m && board[i+1][j+1]==1)
count++;
if(j+1<m && board[i][j+1]==1)
count++;
if(i-1>=0 && j+1<m && board[i-1][j+1]==1)
count++;
return count;
}
    
    void gameOfLife(vector<vector<int>>& board) {
        int n=board.size();
int m=board[0].size();

    vector<vector<int>> temp( n , vector<int> (m, 0));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            int k=neighbors(i,j,board,n,m);
            if(board[i][j]==0 && k==3)
               temp[i][j]=1;
            
            else if(board[i][j]==1 && k<2)
                temp[i][j]=0;
            
            else if(board[i][j]==1 && (k==2 || k==3))
                temp[i][j]=1;
            
            else if(board[i][j]==1 && k>3)
                temp[i][j]=0;
            
            else
                temp[i][j]=board[i][j];
        }
    }
  
   for(int i=0;i<n;i++){
       for(int j=0;j<m;j++) {
           board[i][j]=temp[i][j];
       }
   }
    
}
    
};
class Solution {
public:
    
    bool helper(int i , int j , int index, int n , int m, vector<vector<char>>& board , string word,vector<vector<bool>>&vis)
    {
        if(board[i][j]==word[index])
        {
            if(index==word.size()-1)
            {
                return true;
            }
            
            vis[i][j]=true;
            
            if(i-1>=0 && vis[i-1][j]==false)
            {
                if(helper(i-1,j,index+1,n,m,board,word,vis))
                {
                    return true;
                }
            }
            
            if(i+1<n && vis[i+1][j]==false)
            {
                if(helper(i+1,j,index+1,n,m,board,word,vis))
                {
                    return true;
                }
            }
            
            if(j-1>=0 && vis[i][j-1]==false)
            {
                if(helper(i,j-1,index+1,n,m,board,word,vis))
                {
                    return true;
                }
            }
            
            if(j+1<m && vis[i][j+1]==false)
            {
                if(helper(i,j+1,index+1,n,m,board,word,vis))
                {
                    return true;
                }
            }
            
            vis[i][j]=false;
            return false;
        }
        return false;
    }
  
    bool exist(vector<vector<char>>& board, string word) {
      
        int n = board.size();
        int m = board[0].size();
        
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(helper(i,j,0,n,m,board,word,vis))
                {
                    return true;
                }
            }
        }
        return false;
        
        
    }
};
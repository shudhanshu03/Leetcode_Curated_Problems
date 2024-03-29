// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    
    void solve(vector<vector<int>> &m, int n,vector<string>&res,vector<vector<int>>&vis,int i,int j,string dum)
    {
        
        
        if(i==n-1 && j==n-1)
        {
            res.push_back(dum);
            return;
        }
        
        if(i+1<n && vis[i+1][j]== 0 && m[i+1][j]==1)
        {
            vis[i][j]=1;
            solve(m,n,res,vis,i+1,j,dum + 'D');
            vis[i][j]=0;
        }
        
        if(j-1>=0 && vis[i][j-1]==0 && m[i][j-1]==1)
        {
            vis[i][j]=1;
            solve(m,n,res,vis,i,j-1,dum+'L');
            vis[i][j]=0;
            
        }
        
        if(j+1<n && vis[i][j+1]==0 && m[i][j+1]==1)
        {
            vis[i][j]=1;
            solve(m,n,res,vis,i,j+1,dum+'R');
            vis[i][j]=0;
        }
        
        if(i-1>=0 && vis[i-1][j]==0 && m[i-1][j]==1)
        {
            vis[i][j]=1;
            solve(m,n,res,vis,i-1,j,dum+'U');
            vis[i][j]=0;
        }
    }
    
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        
        vector<vector<int>>vis(n,vector<int>(n,0));
        vector<string>res;
        if(m[0][0] == 0 || m[n-1][n-1] == 0) 
          return {"-1"};
        
        solve(m,n,res,vis,0,0,""); 
        return res;
        
       }
        
    
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends
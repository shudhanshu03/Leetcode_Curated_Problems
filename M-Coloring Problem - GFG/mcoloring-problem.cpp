// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//Function to determine if graph can be coloured with at most M colours such
//that no two adjacent vertices of graph are coloured with same colour.

bool isSafe(bool graph[101][101],vector<int>&color,int c,int V,int node)
{
    for(int i=0;i<V;i++)
    {
        if(i!=node && graph[i][node]==1 && color[i]==c)
        {
            return false;
        }
    }
    return true;
}

bool solve(bool graph[101][101],vector<int>&color,int m , int V , int node)
{
    if(node == V)
    {
        return true;
    }
    for(int i=1;i<=m;i++)
    {
        if(isSafe(graph,color,i,V,node))
         {
             color[node] = i;
             if(solve(graph,color,m,V,node+1))
             {
                 return true;
             }
             color[node] = -1;
         }
    }
    return false;
}

bool graphColoring(bool graph[101][101], int m, int V)
{
    // your code here
    vector<int>color(V,-1);
    
    
    if(solve(graph,color,m,V,0))
        {
            return true;
        }
    
    return false;        

}

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        cout << graphColoring(graph, m, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends
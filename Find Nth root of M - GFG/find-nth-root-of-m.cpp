// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	int NthRoot(int n, int m)
	{
	    
	    if(m == 1)
	        return 1;
	    
	    int l=2,h=m;
	    
	 
	    while(l<=h)
	    {
	        int mid = l+(h-l)/2;
	        long long int p = pow(mid,n);
	        
	        if(p==m)
	            return mid;
	        
	        else if(p>m || p<0)
	          h=mid-1;  
	        
	        else
	            l=mid+1; 
	        
	    }
	    return -1;
	}  
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		Solution ob;
		int ans = ob.NthRoot(n, m);
		cout << ans << "\n";
	}  
	return 0;
}  // } Driver Code Ends
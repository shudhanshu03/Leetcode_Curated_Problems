 class Solution {
public: 
    
   bool f(int i,int temp, int n, vector<int>&visited,int eachSide, int side, vector<int>&arr){
          
        if(side==1) return true;
       
       if(temp==eachSide)
          return f(0,0,n,visited,eachSide,side-1,arr);
          
        for(int j=i; j<n; j++){
            
            if(visited[j] or (temp+arr[j]>eachSide)) continue;
            visited[j]= true;
            
            if(f(j+1, temp+arr[j],n,visited,eachSide,side,arr)) return true;
             
            visited[j]=false;
            
        }
          
        return false;     
         
     }
    
    bool makesquare(vector<int>& matchsticks) {
         int sum =0;
         int n = matchsticks.size();
        for(auto it: matchsticks) sum +=it;
        
        int  eachSide = sum/4;
        int side =4;
         
        if(n<4 or (sum%4)) return false;
        int i=0;
        int temp =0;
        vector<int>visited(n,false);
        
        return f(i,temp,n,visited,eachSide,side,matchsticks);
        
        
    }
};
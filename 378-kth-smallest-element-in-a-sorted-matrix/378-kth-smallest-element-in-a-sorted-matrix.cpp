class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        
        int l = matrix[0][0];
        int r = matrix.size();
        int c = matrix[0].size();
        int h = matrix[r-1][c-1];
        
        while(l<h)
        {
            int mid = l+(h-l)/2;
            int j = c-1;
            int count = 0;
            for(int i=0;i<r;i++)
            {
                while(j>=0 && matrix[i][j]>mid)
                {
                
                        j--;
                    
                }
                count+=(j+1); 
                
            }
            
            if(count < k)
            {
                l = mid+1;
            }
            else{
                h = mid;
            }
        }
        return l;
    }
};
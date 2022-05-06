class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        
        int i=0,j=n-1;
        int ans;
        while(i<=j)
        {
            int mid = (i+j)/2;
            
            if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1])
            {
               ans = mid;
                break;
            }
            else if(arr[mid]<arr[mid+1])
            {
                i = mid;
            }
            else{
                j = mid;
            }
                
        }
        return ans;
        
    }
};
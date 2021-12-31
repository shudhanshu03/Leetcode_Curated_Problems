class Solution {
public:
    void merge(vector<int>&nums,int low , int mid ,int high,int &c)
    {
        int l = low;
        int h = mid+1;
        
        while(l<=mid && h<=high)
        {
            if((long)nums[l] > (long)2*nums[h])
            {
                c+=(mid-l+1);
                h++;
            }
            else{
                l++;
            }
        }
        sort(nums.begin()+low,nums.begin()+high+1);
    }
    
    void mergesort(vector<int>&nums,int low,int high,int &c)
    {
        
        if(low<high)
        {
            int mid = low+(high-low)/2;
            mergesort(nums,low,mid,c);
            mergesort(nums,mid+1,high,c);
            merge(nums,low,mid,high,c);
        }
    }
    
    int reversePairs(vector<int>& nums) {
        int n = nums.size()-1;
        int c = 0;
        mergesort(nums,0,n,c);
        return c;
    }
};
class Solution {
public:
    void helper(vector<vector<int>>&res,vector<int>&temp,int start,int n , int k)
    {
        if(n<0)
        {
            return; // Return ; No need to check further as the required sum till now become greater than n 
        }
        if(temp.size()==k && n==0)
        {
            res.push_back(temp); // Found the combination so just push that into res vector
            return;
        }
        
        for(int i=start;i<=9;i++)
        {
            temp.push_back(i); // includes the ith value
            helper(res,temp,i+1,n-i,k); // check values after that as each number should be used at most once
            temp.pop_back(); // pop_back the last value included as that combination doesn't make the sum
        }
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>res; // creating the resultant vector
        vector<int>temp; // creating temp vector to store possible combinations
        helper(res,temp,1,n,k); // calling the helper function
        
        return res; // returning our resultant vector
    }
};
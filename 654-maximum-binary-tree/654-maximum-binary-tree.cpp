/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxxe(vector<int>&nums)
    {
        int re = INT_MIN;
        int index = 0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>re)
            {
                re = nums[i];
                index = i;
            }
        }
        return index;
    }
    
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        
        if(nums.size()==0)
        {
            return NULL;
        }
        int pivot = maxxe(nums);
        int maxe = nums[pivot];
        vector<int>left;
        vector<int>right;
        for(int i=0;i<pivot;i++)
        {
            left.push_back(nums[i]);
        }
        for(int i=pivot+1;i<nums.size();i++)
        {
            right.push_back(nums[i]);
        }
        TreeNode *root = new TreeNode(maxe);
        root->left = constructMaximumBinaryTree(left);
        root->right = constructMaximumBinaryTree(right);
        
        return root;
        
        
    }
};
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
    int kth(TreeNode* root , int &k)
    {
        
    if(root==NULL)
        {
            return 0;
        }
        
        int res = kth(root->left,k);
        
        if(res!=0)
        {
            return res;
        }
        k--;
        if(k==0)
        {
            return root->val;
        }

        return kth(root->right,k);;
        
    }
    int kthSmallest(TreeNode* root, int k) {
        
        return kth(root,k);
    } 
        
};
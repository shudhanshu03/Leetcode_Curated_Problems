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
    TreeNode *fun(TreeNode*root,TreeNode*node)
    {
        if(root==NULL)
        {
            return node;
        }
        
        if(root->val > node->val)
        {
            root->left = fun(root->left,node);
        }
        if(root->val < node->val)
        {
            root->right = fun(root->right,node);
        }
        return root;
    }
    
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        
        TreeNode* node = new TreeNode(val);
        if(root==NULL)
        {
            return node;
        }
        TreeNode *newroot = fun(root,node);
        
        return newroot;
        
        
    }
};
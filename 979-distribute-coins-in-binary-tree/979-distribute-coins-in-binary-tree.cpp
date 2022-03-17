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
    int res = 0;
    int help(TreeNode* root)
    {
        if(root==NULL)
        {
            return 0;
        }
        int lh = help(root->left);
        int rh = help(root->right);
        
        res+= abs(lh)+abs(rh);
        
        return (lh+rh+root->val-1);
    }
    
    int distributeCoins(TreeNode* root) {
        help(root);
        return res;
    }
};
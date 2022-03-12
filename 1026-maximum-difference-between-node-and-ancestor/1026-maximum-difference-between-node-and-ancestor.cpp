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
    int help(TreeNode *root , int curmin , int curmax)
    {
        if(root==NULL)
        {
            return curmax-curmin;
        }
        curmin = min(curmin,root->val);
        curmax = max(curmax,root->val);
        int ls = help(root->left,curmin,curmax);
        int rs = help(root->right,curmin,curmax);
        
        return max(ls,rs);
    }
    
    int maxAncestorDiff(TreeNode* root) {
        if(root==NULL)
        {
            return NULL;
        }
        
        int res = help(root,root->val,root->val);
        
        return res;
    }
};
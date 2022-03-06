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
    
    void dfs(TreeNode *root, int level , int &maxlevel , int &res)
    {
        if(root==NULL)
        {
            return;
        }
        
        if(level > maxlevel)
        {
            maxlevel = level;
            res = 0;
        }
        if(level==maxlevel)
        {
            res+=root->val;
        }
        dfs(root->left,level+1,maxlevel,res);
        dfs(root->right,level+1,maxlevel,res);
    }
    
    int deepestLeavesSum(TreeNode* root) {
        int level = 0,maxlevel = 0;
        int res = 0;
        dfs(root,level,maxlevel,res);
        return res;
    }
};
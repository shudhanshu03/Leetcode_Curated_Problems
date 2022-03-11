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
    void treeContent(TreeNode *root , vector<int>&res)
    {
        if(root==NULL)
        {
            return;
        }
        treeContent(root->left,res);
        res.push_back(root->val);
        treeContent(root->right,res);
    }
    TreeNode *resRoot(int l,int h,vector<int>&res)
    {
        if(l>h)
        {
            return NULL;
        }
        
        int rootnode = (l+h)/ 2;
        TreeNode *root = new TreeNode(res[rootnode]);
        root->left = resRoot(l,rootnode-1,res);
        root->right = resRoot(rootnode+1,h,res);
        
        
        return root;
        
        
    }
    
    TreeNode* balanceBST(TreeNode* root) {
        if(root==NULL)
        {
            return NULL;
        }
        vector<int>res;
        treeContent(root,res);
        int n = res.size()-1;
        TreeNode *resRoo = resRoot(0,n,res);
        return resRoo;
    }
};
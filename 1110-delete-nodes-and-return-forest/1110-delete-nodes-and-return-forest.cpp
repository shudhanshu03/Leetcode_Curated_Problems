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
    vector<TreeNode*>res;
    
    void dfs(TreeNode* &root, vector<int>&to_delete)
    {
        if(root==NULL)
        {
            return;
        }
        dfs(root->left,to_delete);
        dfs(root->right,to_delete);
        
        if(find(to_delete.begin(),to_delete.end(),root->val)!=to_delete.end())
        {
            if(root->left)
            {
                res.push_back(root->left);
            }
            if(root->right)
            {
                res.push_back(root->right);
            }
            root=NULL;
            delete root;
        }
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        if(root==NULL)
        {
            return res;
        }
        dfs(root,to_delete);
         if(root)
        {
           res.push_back(root); 
        }
        
        return res;
    }
};
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
    TreeNode* lca(TreeNode* root , int startValue , int destValue)
    {
       if(root==NULL)
       {
           return NULL;
       }
       
       if(root->val==startValue || root->val==destValue)
       {
           return root;
       }
       TreeNode* left = lca(root->left,startValue,destValue);
       TreeNode* right = lca(root->right,startValue,destValue);
       
       if(left && right)
       {
           return root;
       }
       else if(!left && right)
       {
           return right;
       }
       else if(!right && left){
           return left;
       }
        else{
            return NULL;
        }
    }
    
    bool dfs(TreeNode*root , int a , string &s)
    {
        if(root==NULL)
        {
            return false;
        }
        if(root->val==a)
        {
            return true;
        }
        s+='L';
        if(dfs(root->left,a,s))
        {
            return true;
        }
        s.pop_back();
        s+='R';
        if(dfs(root->right,a,s))
        {
            return true;
        }
        s.pop_back();
        return false;
    }
    
    string getDirections(TreeNode* root, int startValue, int destValue) {
        
        TreeNode* lcanode = lca(root,startValue,destValue);
        
        string sp = ""; // source path from the lca
        string dp = ""; // dest path from the lca
            
        dfs(lcanode,startValue,sp);
        
        for(int i=0;i<sp.length();i++)
        {
            sp[i]='U';
        }
        dfs(lcanode,destValue,dp);
        
        return sp+dp;
        
    }
};
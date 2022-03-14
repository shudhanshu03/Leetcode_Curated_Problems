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
   void count(TreeNode* root , int maxi , int &c)
    {
         if(root==NULL)
         {
             return;     
         }
         if(root->val >= maxi)
         {
             c++;
             maxi = root->val;
         }
         
         count(root->left,maxi,c);
         count(root->right,maxi,c);
         
         
        
    }
    
    int goodNodes(TreeNode* root) {
        
       int c = 0; 
       int maxi  = root->val; 
       count(root,maxi,c);
       return c;
    }
};
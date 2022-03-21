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
    int sum(TreeNode*root , int cs , int targetSum)
    {
        if(root==NULL)
        {
            return 0;
        }
        cs+=root->val;
        
        return (cs==targetSum) + sum(root->left,cs,targetSum) + sum(root->right,cs,targetSum);
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(root==NULL)
        {
            return 0;
        }
        return sum(root,0,targetSum) + pathSum(root->left,targetSum) + pathSum(root->right,targetSum);
    }
};
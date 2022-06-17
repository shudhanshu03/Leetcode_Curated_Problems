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
        int c = 0;
    int mincam(TreeNode* root){
        if(root==NULL)
            return 0;
        int left = mincam(root->left);
        int right = mincam(root->right);
        
        if(left == -1 || right == -1){  
            c++;
            return 1;
        }
        if(left==1 || right ==1)       
            return 0;
        
        return -1;
        
    }
    int minCameraCover(TreeNode* root) {
        if(mincam(root)==-1)
            return ++c;
        else
            return c;
    
    }
};
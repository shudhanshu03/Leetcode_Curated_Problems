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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
         
        int rootIndex = 0;
        
        return build(preorder,inorder,0,inorder.size()-1,rootIndex);
        
    }
    
    TreeNode* build(vector<int>&preorder,vector<int>&inorder,int start,int end,int &rootIndex)
    {
        if(start > end)
        {
            return NULL;
        }
        int pivot = start;
        
        while(inorder[pivot]!=preorder[rootIndex])
        {
            pivot++;
        }
        rootIndex++;
        TreeNode *root = new TreeNode(inorder[pivot]);
        root->left = build(preorder,inorder,start,pivot-1,rootIndex);
        root->right = build(preorder,inorder,pivot+1,end,rootIndex);
        
        return root;
    }
};
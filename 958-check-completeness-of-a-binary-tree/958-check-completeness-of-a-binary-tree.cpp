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
    bool isCompleteTree(TreeNode* root) {
        if(root==NULL)
        {
            return true;
        }
        queue<TreeNode*>q;
        q.push(root);
        bool flag = 0;
        
        while(q.empty()==false)
        {
            
            auto it=q.front();
            q.pop();
            
            if(it==NULL)
            {
                flag=true;
            }
            else{
                if(flag)
                {
                    return false;
                }
                q.push(it->left);
                q.push(it->right);
            }
        }
        return true;
    }
};
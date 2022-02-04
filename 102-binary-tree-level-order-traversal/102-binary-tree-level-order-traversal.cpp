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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>res;
        if(root==NULL)
        {
            return {};
        }
        queue<TreeNode*>q;
        
        q.push(root);
        vector<int>dum;
        
        while(q.empty()==false)
        {
            int sz = q.size();
            
            for(int i=0;i<sz;i++)
            {
                TreeNode *temp = q.front();
                q.pop();
                dum.push_back(temp->val);
                
                if(temp->left)
                {
                    q.push(temp->left);
                }
                if(temp->right)
                {
                    q.push(temp->right);
                }
            }
            res.push_back(dum);
            dum.clear();
        }
        return res;
    }
};
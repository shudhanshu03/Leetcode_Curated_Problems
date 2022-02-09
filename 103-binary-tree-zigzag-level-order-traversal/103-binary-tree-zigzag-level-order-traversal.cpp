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
    
    
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>res;
        if(root==NULL)
        {
            return res;
        }
        queue<TreeNode*>q;
        
        q.push(root);
        bool flag = 0;
        while(q.empty()==false)
        {
              int sz = q.size();
              vector<int>ans;
              for(int i=0;i<sz;i++)
              {
                TreeNode *temp = q.front();
                q.pop();
                ans.push_back(temp->val);
                
                if(temp->left)
                {
                   q.push(temp->left); 
                }
                 if(temp->right)
                 {
                     q.push(temp->right);
                 }
              }
             if(flag)
             {
                 reverse(ans.begin(),ans.end());
             }
            flag = !flag;
             res.push_back(ans);
              
        }
        return res;
    }      
};
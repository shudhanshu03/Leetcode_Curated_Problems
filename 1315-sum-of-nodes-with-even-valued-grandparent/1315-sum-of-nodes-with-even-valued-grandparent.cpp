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
    int sumEvenGrandparent(TreeNode* root) {
        if(root==NULL)
        {
            return 0;
        }
        queue<TreeNode *>q;
        q.push(root);
        int res = 0;
        while(q.empty()==false)
        {
            int sz = q.size();
            
            while(sz--)
            {
                TreeNode *temp = q.front();
                q.pop();
                bool even = 0;
                if(temp->val %2 ==0)
                {
                    even = 1;
                }
                if(temp->left)
                {
                    q.push(temp->left);
                    if(even)
                    {
                       if(temp->left->left) 
                       {
                          res+=temp->left->left->val; 
                       }
                         
                       if(temp->left->right) 
                       {
                          res+=temp->left->right->val; 
                       }
                    }
                    
                }
                if(temp->right)
                {
                    q.push(temp->right);
                    if(even)
                    {
                       if(temp->right->left) 
                       {
                          res+=temp->right->left->val; 
                       }
                         
                       if(temp->right->right) 
                       {
                          res+=temp->right->right->val; 
                       }
                         
                    }
                }
              }   
        }
        return res;
    }
};
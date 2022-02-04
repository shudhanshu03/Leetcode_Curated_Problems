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
    int widthOfBinaryTree(TreeNode* root) {
        
        if(root==NULL)
        {
            return 0;
        }
        int res = INT_MIN;
        queue<pair<TreeNode*,unsigned long long int>>q;
        
        q.push({root,0});
        
        while(q.empty()==false)
        {
            auto it = q.front();
            int si = q.size();
            
            unsigned long long int leftindex = it.second;
            unsigned long long int rightindex = 0;
            for(int i=0;i<si;i++)
            {
                auto ii = q.front();
                TreeNode *te = ii.first;
                q.pop();
                rightindex = ii.second;
                
                if(te->left)
                {
                    q.push({te->left,2*rightindex+1});
                }
                if(te->right)
                {
                    q.push({te->right,2*rightindex+2});
                }
            }
            res = max(res,int(rightindex-leftindex+1));
            
            
        }
        return res;
    }
};
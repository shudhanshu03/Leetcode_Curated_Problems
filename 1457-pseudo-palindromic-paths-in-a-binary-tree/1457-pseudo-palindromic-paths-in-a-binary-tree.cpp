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
    unordered_map<int,int>m;
    int c=0;
    
    void help(TreeNode *root)
    {
        if(root==NULL)
        {
            return;
        }
        m[root->val]++;
        
        if(!root->left && !root->right)
        {
            int o=0;
            for(auto i:m)
            {
                if(i.second %2!=0)
                {
                    o++;
                }
            }
            if(o<=1)
            {
                c++;
            }
        }
        help(root->left);
        help(root->right);
        
        m[root->val]--;
        
    }
    int pseudoPalindromicPaths (TreeNode* root) {
       help(root);
       return c; 
    }
};
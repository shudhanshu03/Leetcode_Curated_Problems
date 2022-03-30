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
    long long sum = 0;
    long long ans = 0;
    long long tsum=0;
    void dfs(TreeNode* root)
    {
        if(root==NULL)
        {
            return;
        }
        sum+=root->val;
        dfs(root->left);
        dfs(root->right);
        
    }
    int cal(TreeNode*root)
    {
        if(root==NULL)
        {
            return 0;
        }
        int l = cal(root->left);
        int h = cal(root->right);
        tsum = root->val+l+h;
        ans = max(ans,(sum-tsum)*tsum);
        return tsum;
        
    }
    int maxProduct(TreeNode* root) {
        dfs(root);
        cal(root);
        int mod=1e9+7;
        return ans%mod;
    }
};
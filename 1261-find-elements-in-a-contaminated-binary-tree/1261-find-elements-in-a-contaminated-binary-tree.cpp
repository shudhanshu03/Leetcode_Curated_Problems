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
class FindElements {
public:
    set<int>s;
        
    
    FindElements(TreeNode* root) {
        root->val = 0;
        fill(root,0);
        
    }
    
    void fill(TreeNode *root,int vall)
    {
        root->val = vall;
        s.insert(vall);
        if(root->left)
        {
            fill(root->left,2*root->val+1);
        }
        if(root->right)
        {
            fill(root->right,2*root->val+2);
        }
    }
    
    bool find(int target) {
        
        if(s.find(target)!=s.end())
        {
            return true;
        }
        return false;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
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
class BSTIterator {
    stack<TreeNode *>s;
public:
    BSTIterator(TreeNode* root) {
        push(root);
    }
    
    int next() {
        TreeNode *temp = s.top();
        s.pop();
        push(temp->right);
        return temp->val;
    }
    
    bool hasNext() {
        return !s.empty();
    }
    
    void push(TreeNode *root)
    {
       while(root!=NULL)
       {
           s.push(root);
           root = root->left;
       }
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
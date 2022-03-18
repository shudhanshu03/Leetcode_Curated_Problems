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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        
        map<int,TreeNode*>m;
        
        for(auto i:descriptions)
        {
            int par = i[0];
            int ch = i[1];
            int isleft = i[2];
            
            if(m.find(par)==m.end())
            {
                TreeNode *node = new TreeNode(par);
                m[par]=node;
            }
            if(m.find(ch)==m.end())
            {
                TreeNode *child = new TreeNode(ch);
                m[ch]=child;
            }
            
            if(isleft==1)
            {
                m[par]->left = m[ch];
            }
            else{
                m[par]->right = m[ch];
            }
        }
        
        
        set<int>s;
        set<int>s1;
        for(auto i:descriptions)
        {
            s.insert(i[0]);
            s1.insert(i[1]);
        }
        int parent;
        for(auto i:s)
        {
            if(s1.find(i)==s1.end())
            {
                parent = i;
                break;
            }
        }
        return m[parent];
    }
};
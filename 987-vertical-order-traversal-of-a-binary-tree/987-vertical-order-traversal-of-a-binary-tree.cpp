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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        map<int,map<int,multiset<int>>>m; 
        
        queue<pair<TreeNode*, pair<int,int>>>q;
        
        q.push({root,{0,0}});
        
        while(q.empty()==false)
        {
            auto it = q.front();
            q.pop();
            TreeNode *temp = it.first;
            int vertical = it.second.first;
            int level = it.second.second;
            
            
            m[vertical][level].insert(temp->val);
            
            if(temp->left)
            {
                q.push({temp->left,{vertical-1,level+1}});
            }
            if(temp->right)
            {
                q.push({temp->right,{vertical+1,level+1}});
            }
        }
        
        vector<vector<int>>res;
        
        for(auto q:m)
        {
            vector<int>dum;
            for(auto qq:q.second)
            {
                dum.insert(dum.end(),qq.second.begin(),qq.second.end());
            }
            res.push_back(dum);
        }
        return res;
        
        
    }
};
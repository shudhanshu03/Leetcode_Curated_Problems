/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void make_parent(TreeNode* root,unordered_map<TreeNode*, TreeNode*>&parent)
    {
        queue<TreeNode*>q;
        
        q.push(root);
        while(q.empty()==false)
        {
            int sz = q.size();
            
            while(sz--)
            {
                TreeNode*temp = q.front();
                q.pop();
                if(temp->left)
                {
                    q.push(temp->left);
                    parent[temp->left]=temp;
                }
                if(temp->right)
                {
                    q.push(temp->right);
                    parent[temp->right]=temp;
                }
            }
        }
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*>parent;
        make_parent(root,parent);
        
        queue<TreeNode*>q;
        q.push(target);
        unordered_map<TreeNode*,bool>visited;
        visited[target]=true;
        int c=0;
        while(q.empty()==false)
        {
            int sz = q.size();
            if(c==k)
            {
                break;
            }
            c++;
            while(sz--)
            {
                TreeNode* temp = q.front();
            q.pop();
            
            
            if(temp->left && visited[temp->left]==false)
            {
                q.push(temp->left);
                visited[temp->left]=true;
            }
            if(temp->right && visited[temp->right]==false)
            {
                q.push(temp->right);
                visited[temp->right]=true;
            }
            if(parent[temp] && visited[parent[temp]]==false)
            {
                q.push(parent[temp]);
                visited[parent[temp]]=true;
            }
            }
            
        }
        
        vector<int>res;
        while(q.empty()==false)
        {
            TreeNode* temp = q.front();
            q.pop();
            res.push_back(temp->val);
            
        }
        return res;
    }
};
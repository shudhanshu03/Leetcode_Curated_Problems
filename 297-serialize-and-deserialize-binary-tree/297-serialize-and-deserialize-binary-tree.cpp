/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==NULL)
        {
            return "null";
        }
        return to_string(root->val) + ',' + serialize(root->left) + ',' + serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        
        string s;
        queue<string>q;
        for(int i=0;i<data.size();i++)
        {
            if(data[i]==',')
            {
                q.push(s);
                s="";
                continue;
            }
            s+=data[i];
        }
        if(s.size())
        {
            q.push(s);
        }
        return help(q);
    }
    
    TreeNode* help(queue<string>&q)
    {
        
        string a = q.front();
        q.pop();
        
        if(a=="null")
        {
            return NULL;
        }
        TreeNode *root = new TreeNode(stoi(a));
        root->left = help(q);
        root->right = help(q);
        
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
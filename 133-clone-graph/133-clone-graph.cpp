/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    
    void dfs(Node* node , Node *copy , vector<Node*>&vis)
    {
        vis[copy->val] = copy;
        
        for(auto q:node->neighbors)
        {
            if(vis[q->val]==0)
            {
                Node *x = new Node(q->val);
                (copy->neighbors).push_back(x);
                dfs(q,x,vis);
            }
            else{
                (copy->neighbors).push_back(vis[q->val]);
            }
        }
    }
    Node* cloneGraph(Node* node) {
        if(node==NULL)
        {
            return NULL;
        }
        vector<Node*>vis(1000,0);
        Node *copy = new Node(node->val);
        dfs(node,copy,vis);
        return copy;
    }
};
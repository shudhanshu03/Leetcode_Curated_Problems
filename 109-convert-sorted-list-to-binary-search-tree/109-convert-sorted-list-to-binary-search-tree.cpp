/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* dfs(ListNode* head , ListNode* tail)
    {
        if(head==tail)
        {
            return NULL;
        }
        if(head->next==tail)
        {
            TreeNode *node = new TreeNode(head->val);
            return node;
        }
        
        ListNode *mid=head,*fast=head;
        while(fast!=tail && fast->next!=tail)
        {
            mid = mid->next;
            fast = fast->next->next;
        }
        
        TreeNode *node = new TreeNode(mid->val);
        node->left = dfs(head,mid);
        node->right = dfs(mid->next,tail);
        
        return node;
    }
    
    TreeNode* sortedListToBST(ListNode* head) {
        TreeNode* newroot = dfs(head,NULL);
        return newroot;
    }
};
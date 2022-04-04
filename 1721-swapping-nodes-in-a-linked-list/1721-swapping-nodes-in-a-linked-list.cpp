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
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *slow = head;
        ListNode *fast = head;
        int n = 0;
        ListNode *curr = head;
        while(curr!=NULL)
        {
            n++;
            curr =curr->next;
        }
        for(int i=1;i<k;i++)
        {
            slow = slow->next;
        }
        for(int i=1;i<=n-k;i++)
        {
            fast=fast->next;
        }
        swap(slow->val,fast->val);
        return head;
    }
};
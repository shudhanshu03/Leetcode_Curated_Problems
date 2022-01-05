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
    
    ListNode *reverse(ListNode *head , ListNode *temp)
    {
        ListNode *prev = temp;
        ListNode *ne;
        
        while(head!=temp)
        {
            ne = head->next;
            head->next = prev;
            prev = head;
            head = ne;
        }
        return prev;
    }
    
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        ListNode *temp = head;
        
        for(int i=0;i<k;i++)
        {
            if(temp==NULL)
            {
                return head;
            }
            temp = temp->next;
        }
        ListNode *newnode = reverse(head,temp);
        
        head->next = reverseKGroup(temp,k);
        
        return newnode;
    }
};
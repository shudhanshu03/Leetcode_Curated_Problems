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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        ListNode *head = new ListNode(0);
		ListNode *temp = head;

		while (list2 && list1){
			if (list1->val <= list2->val){
				temp->next = list1;                
				list1 = list1->next;
			}
			else{
				temp->next = list2;
				list2 = list2->next;
			}
			temp = temp->next;
		}
		if (list1){
			temp->next = list1;
		}
		else if (list2){
			temp->next = list2;
		}
		return head->next;
    }
};
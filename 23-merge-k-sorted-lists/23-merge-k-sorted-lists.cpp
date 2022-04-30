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
class comparator{
    public:
    bool operator()(ListNode *x,ListNode *y){
        return (x->val>y->val);
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,comparator> pq;
        
        for(int i=0;i<lists.size();i++){
            if(lists[i])
                pq.push(lists[i]);
        }
        ListNode *dummy=new ListNode(-1);
        ListNode *tail=dummy;
        
        while(!pq.empty()){
            ListNode *top=pq.top();
            pq.pop();
            tail->next=top;
            tail=tail->next;
            if(top->next)
                pq.push(top->next);
        }   
        return dummy->next;
    }
};
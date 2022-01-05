
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *temp=headA, *temp1=headB;
        int a=0,b=0;
        
        
        while(temp!=NULL && temp1!=NULL){
            temp=temp->next;
            temp1=temp1->next;
        }
        
        
        if(temp==NULL){
            while(temp1!=NULL){
                temp1 = temp1->next;
                b++;
            }
        }else{
            while(temp!=NULL){
                temp = temp->next;
                a++;
            }
        }
        
        temp = headA;
        temp1 = headB;
        
        
        for(int i=0;i<a;i++){
            temp = temp->next;
        }
        for(int i=0;i<b;i++){
            temp1=temp1->next;
        }
        
        
        while(temp!=NULL || temp1!=NULL){
            if(temp==temp1) return temp;
            temp = temp->next ;
            temp1 = temp1->next;
        }
        
        return NULL;
    
    }
};
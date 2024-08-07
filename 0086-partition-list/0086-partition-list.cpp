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
    ListNode* partition(ListNode* head, int x) {
        
        if(head==NULL)
        {
            return head;
        }
        
        
        ListNode* prev = new ListNode(-1);
        ListNode* p = head;
        prev->next=p;
        
        ListNode* h = prev;
        
        while(p!=NULL && p->val<x)
        {
            prev=prev->next;
            p=p->next;
        }
        
        if(p==NULL)
        {
            return h->next;
        }
        
        cout<<prev->val<<" "<<p->val;
        
        ListNode* previous=p;
        ListNode* current = p->next;
        
        while(current!=NULL)
        {
            if(current->val<x)
            {
                ListNode* temp = current->next;
                
                prev->next=current;
                current->next=p;
                prev=prev->next;
                
                previous->next=temp;
                current=temp;
                
                
                
            }else{
                
                previous=previous->next;
                current=current->next;
                
            }
            
        }
        
        
        return h->next;
        
        
        
    }
};
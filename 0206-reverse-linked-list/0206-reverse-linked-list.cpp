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
    
    
  void reverselink(ListNode*& head,ListNode* cur,ListNode* prev)
    {
        
        if(cur==NULL)
        {
            head=prev;
            return;
        }
        
        
       
        
      reverselink(head,cur->next,cur);
         cur->next=prev;
        
        
    }
    
    
    
    ListNode* reverseList(ListNode* head) {
        
        ListNode* cur = head;
        ListNode* prev = NULL;
        reverselink(head,cur,prev);
        
        
        
        
        return head;
        
       /* if(head==NULL)
        {
            return head;
        }
        
        ListNode* p = NULL;
        ListNode* q = head;
        ListNode* r;
        
        
        while(q->next!=NULL)
        {
            r=q->next;
            q->next=p;
            p=q;
            q=r;
        }
        
        
        
        q->next=p;
        
        return q;*/
        
        
        
        
        
        
        
    }
};
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
    ListNode* deleteDuplicates(ListNode* head) {
        
        
        if(head==NULL)
        {
            return head;
            
        }
        
       
        ListNode* cur = head;
        ListNode* next = head->next;
        ListNode* prevtail;
        int a;
        
       while(cur->next!=NULL)
       {
           a=0;
           next=cur->next;
           while(next!=NULL && cur->val==next->val)
           {
               a++;
               next=next->next;
           }
           if(a>0)
           {
               if(cur==head)
               {
                   head=next;
                   cur=next;
                   if(cur==NULL)
                   {
                       return NULL;
                   }
                       
               }else{
                   prevtail->next=next;
                   cur=next;
                   if(cur==NULL)
                   {
                       return head;
                   }
                   
                 
               }
           }else{
               
               prevtail=cur;
               cur=cur->next;
               
               
           }
           
       }
        
        
        return head;
        
    }
};
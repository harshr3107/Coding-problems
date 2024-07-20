/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        
          ListNode* slow = head;
        ListNode* fast = head;
        
        if(head==NULL || head->next==NULL || head->next->next==NULL)
        {
            return NULL;
        }
         
        slow=head->next;
        fast=head->next->next;
        int a=0;
        
      
        
        
        while(fast->next!=NULL && slow!=fast)
        {
            if(slow==fast)
            {
               
                break;
            }
            
            slow=slow->next;
            fast=fast->next->next;
            if(fast==NULL)
            {
                return NULL;
            }
            
            
        }
        
        if(fast==NULL || fast->next==NULL)
        {
            return NULL;
        }
        
        
        ListNode* temp = head;
        
        while(temp!=slow)
        {
            temp=temp->next;
            slow=slow->next;
        }
        
        
        
        
        return slow;
        
        
    }
};
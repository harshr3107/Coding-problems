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
    bool hasCycle(ListNode *head) {
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        if(head==NULL || head->next==NULL || head->next->next==NULL)
        {
            return false;
        }
         
        slow=head->next;
        fast=head->next->next;
        
        
        
        while(fast->next!=NULL)
        {
            if(slow==fast)
            {
                return true;
            }
            
            slow=slow->next;
            fast=fast->next->next;
            if(fast==NULL)
            {
                return false;
            }
            
            
        }
        
        
        return false;
    }
};
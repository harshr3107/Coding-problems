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
    
    
    ListNode* getmiddle(ListNode* head)
    {
        if(head==NULL || head->next==NULL)
        {
            return head;
        }
        
        ListNode* slow=head;
        ListNode* fast=head;
        
        while(fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        
        
        return slow;
        
        
    }
    
    ListNode* deleteMiddle(ListNode* head) {
        
        if(head->next==NULL)
        {
            return NULL;
        }
        
        ListNode* mid = getmiddle(head);
        
        ListNode* prev = head;
        
        while(prev->next!=mid)
        {
            prev=prev->next;
        }
        
        prev->next=mid->next;
        
        return head;
        
    }
};
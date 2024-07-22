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
        ListNode* slow=head;
        ListNode* fast = head;
        
        while(fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        
        
        return slow;
        
    }
    
    
    ListNode* reversefrommid(ListNode* head)
    {
        ListNode* prev = NULL;
        ListNode* cur = head;
        ListNode* next;
        
        
        while(cur!=NULL)
        {
            next=cur->next;
            cur->next=prev;
            prev=cur;
            cur=next;
            
        }
        
        return prev;
        
        
    }
    
   
    
    
    bool isPalindrome(ListNode* head) {
        
        
        if(head==NULL || head->next==NULL)
        {
            return true;
        }
        
        ListNode* middle = getmiddle(head);
        ListNode* h = reversefrommid(middle);
        
        while(h!=NULL && head!=NULL)
        {
            if(h->val!=head->val)
            {
                return false;
            }
            h=h->next;
            head=head->next;
            
        }
        
        return true;
        
        
        
    }
};
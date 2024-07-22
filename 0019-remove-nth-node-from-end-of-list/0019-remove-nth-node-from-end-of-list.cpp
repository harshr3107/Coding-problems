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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        if(head==NULL || head->next==NULL)
        {
            return NULL;
        }
        
        
        int length=0;
        ListNode* temp = head;
        ListNode* temp2 = head->next;
        
        
        while(temp!=NULL)
        {
            length++;
            temp=temp->next;
        }
        
        if(length==n)
        {
            head=head->next;
            return head;
        }
        
        int i=1;
        temp=head;
        
        
        while(i<length-n)
        {
            i++;
            temp=temp->next;
            temp2=temp2->next;
            
        }
        
        temp->next=temp2->next;
        delete(temp2);
        
        return head;
        
        
        
    }
};
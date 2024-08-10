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



ListNode* reverselinkedlist(ListNode* head)
{
    ListNode* prev = NULL;
    ListNode* curr = head;
    ListNode* nextt;
    
    while(curr!=NULL)
    {
        nextt = curr->next;
        curr->next=prev;
        prev=curr;
        curr=nextt;
        
    }
    
    
    return prev;
    
}



class Solution {
public:
    int getDecimalValue(ListNode* head) {
        
        head = reverselinkedlist(head);
        int num=0;
        int a=1;
        
        while(head!=NULL)
        {
            num += (head->val)*a;
            a=a*2;
            head=head->next;
        }
        
        
        return num;
        
    }
};
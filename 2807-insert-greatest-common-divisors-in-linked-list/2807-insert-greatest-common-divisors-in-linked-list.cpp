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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        
        if(head==NULL || head->next==NULL)
        {
            return head;
        }
        
        
        ListNode* n1=head;
        ListNode* n2=head->next;
        ListNode* n3;
        
        while(n2!=NULL)
        {
            n3=n2->next;
            int a  = gcd(n1->val,n2->val);
            ListNode* n = new ListNode(a);
            n1->next=n;
            n->next=n2;
            n1=n2;
            n2=n3;
        }
        
        
        return head;
        
        
        
        
        
    }
};
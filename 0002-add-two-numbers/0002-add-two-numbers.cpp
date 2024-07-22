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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        int carry=0;
        ListNode* anshead= new ListNode(-1);
        ListNode* tempo = anshead;
        int sum=0;
        int temp=sum;
        
        while(l1!=NULL && l2!=NULL)
        {
            
            sum=l1->val+l2->val+carry;
            carry=0;
            
            if((sum/10)>0)
            {
                carry=(sum/10)%10;
                sum=sum%10;
            }
            
            ListNode* n = new ListNode(sum);
            tempo->next=n;
            tempo=tempo->next;
            
            l1=l1->next;
            l2=l2->next;
        }
        
        
        while(l1!=NULL)
        {
            sum=l1->val+carry;
            carry=0;
            
            
            if((sum/10)>0)
            {
                carry=(sum/10)%10;
                sum=sum%10;
            }
            
            ListNode* n = new ListNode(sum);
            tempo->next=n;
            tempo=tempo->next;
            l1=l1->next;
            
        }
        
        
        
        while(l2!=NULL)
        {
            
            sum=l2->val+carry;
            carry=0;
            
            if((sum/10)>0)
            {
                carry=(sum/10)%10;
                sum=sum%10;
            }
            
            ListNode* n = new ListNode(sum);
            tempo->next=n;
            tempo=tempo->next;
            l2=l2->next;
            
            
        }
        
        
        if(carry!=0)
        {
            ListNode* n = new ListNode(carry);
            tempo->next=n;
            tempo=tempo->next;
        }
        
        
        return anshead->next;
        
        
    }
};
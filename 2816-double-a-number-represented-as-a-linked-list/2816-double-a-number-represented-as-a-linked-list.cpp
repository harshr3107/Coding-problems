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
    
    
    
    ListNode* reverse(ListNode* head)
    {
        if(head==NULL || head->next==NULL)
        {
            return head;
        }
        
        ListNode* curr=head;
        ListNode* prev=NULL;
        ListNode* next;
        
        
        while(curr!=NULL)
        {
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
            
        }
        
        
        return prev;
        
        
        
        
        
    }
    
    
    
    
    void display(ListNode* head)
    {
        while(head!=NULL)
        {
            cout<<head->val<<" ";
            head=head->next;
        }
        
        cout<<endl;
    }
    
    
    
    ListNode* doubleIt(ListNode* head) {
        
        //display(head);
       head = reverse(head);
        //display(head);
        
        ListNode* prev = new  ListNode(-1);
        prev->next=head;
        
        int carry=0;
        
        ListNode* s;
        
        while(head!=NULL)
        {
            s=head;
            int h = head->val*2+carry;
            int digit = h%10;
            head->val=digit;
            h=h/10;
            carry=h;
            head=head->next;
            
        }
        
        if(carry!=0)
        {
            ListNode* n = new ListNode(carry);
            s->next=n;
        }
        
       // display(prev->next);
        
        head = reverse(prev->next);
        
        
        return head;
        
        
    }
};
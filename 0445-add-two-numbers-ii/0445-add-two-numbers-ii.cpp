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
    
    
    ListNode* reversee(ListNode* h)
    {
        
        ListNode* prev = NULL;
        ListNode* curr = h;
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
    
    
    void display(ListNode* h)
    {
        while(h!=NULL)
        {
            cout<<h->val<<" ";
            h=h->next;
        }
        
        cout<<endl;
    }
    
    
    
    
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* l1r=reversee(l1);
        ListNode* l2r=reversee(l2);
        
        ListNode* ans = NULL;
        ListNode* prev= new ListNode(-1);
        prev->next=ans;
        
        int sum=0;
        int carry=0;
        
        while(l1r!=NULL && l2r!=NULL)
        {
            sum=l1r->val+l2r->val+carry;
            carry=0;
            int csum = sum%10;
            sum=sum/10;
            carry=sum;
            
            ListNode* temp = new ListNode(csum);
            
            
            
            if(ans==NULL)
            {
                prev=temp;
                ans=temp;
                
                
            }else{
                
                ans->next=temp;
                ans=ans->next;
                
            }
            
            l1r=l1r->next;
            l2r=l2r->next;
            
        }
        
        while(l1r!=NULL)
        {
            sum=l1r->val+carry;
            carry=0;
            int csum = sum%10;
            sum=sum/10;
            carry=sum;
            
            ListNode* temp = new ListNode(csum);
            
            
            
            if(ans==NULL)
            {
                prev=temp;
                ans=temp;
                
                
            }else{
                
                ans->next=temp;
                ans=ans->next;
                
            }
            
            l1r=l1r->next;
            
            
        }
        
        
        
         while(l2r!=NULL)
        {
            sum=l2r->val+carry;
            carry=0;
            int csum = sum%10;
            sum=sum/10;
            carry=sum;
            
            ListNode* temp = new ListNode(csum);
            
            
            
            if(ans==NULL)
            {
                prev=temp;
                ans=temp;
                
                
            }else{
                
                ans->next=temp;
                ans=ans->next;
                
            }
            
            l2r=l2r->next;
            
            
        }
        
       // display(prev);
        
        if(carry!=0)
        {
            ListNode* temp = new ListNode(carry);
            ans->next=temp;
        }
        
        ans = reversee(prev);
        
        
        return ans;
        
        
        
        
        
        
        
    }
};
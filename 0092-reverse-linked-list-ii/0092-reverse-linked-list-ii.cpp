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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        int i;
        
        //LEFT
        
         ListNode* prevfir = head;
         ListNode* fir = head->next;
         
        
        
        
        
        if(left==1)
        {
            
            
            fir=head;
            prevfir=NULL;
            
            
            
        }else{
        
       
        i=2;
        
        while(i!=left)
        {
            prevfir=prevfir->next;
            fir=fir->next;
            i++;
        }
            
            
        }
        
        ListNode* righ = head;
        ListNode* nextrigh = head->next;
        
        
        
        //Right
       
        
        i=1;
        
        while(i!=right)
        {
            righ=righ->next;
            nextrigh=nextrigh->next;
            i++;
            
        }
            
            
        
        
        //cout<<prevfir->val<<" "<<fir->val<<endl;
        //cout<<righ->val<<" "<<nextrigh->val<<endl;
        
        
        
        
       ListNode* prev = NULL;
       ListNode* cur = fir;
       ListNode* nextt; 
        
        
        while(cur!=righ)
        {
            nextt = cur->next;
            cur->next=prev;
            prev=cur;
            cur=nextt;
            
        }
        
        cur->next=prev;
        
        
        if(prevfir!=NULL)
        {
        prevfir->next=cur;
        
        }else{
            head=cur;
        }
        
        
        
        fir->next=nextrigh;
        
        return head;
        
    }
};
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
    ListNode* removeZeroSumSublists(ListNode* head) {
        
        ListNode* dummy = new ListNode(-1);
        dummy->next=head;
        
        ListNode* a=head;
        ListNode* b;
        ListNode* prev = dummy;
        int sum=0;
        
        
        while(a!=NULL)
        {
           // cout<<"i entered here for the val "<<a->val<<endl;
            
            ListNode* temp=a;
            while(a!=NULL && a->val==0)
            {
                a=a->next;
            }
            
            if(temp==head && a!=temp)
            {
                head=a;
                //prev->next=head;
                dummy->next=head;
                prev=dummy;
                
            }else{
                prev->next=a;
            }
            
            if(a==NULL)
            {
                prev->next=a;
                
                break;
            }else{
               
                
               b = a->next;
               sum=a->val;
                
                
                while(b!=NULL && sum!=0)
                {
                    sum+=b->val;
                    b=b->next;
                    
                }
                
                
                
                
                if(sum==0)
                {
                    prev->next=b;
                    if(prev==dummy)
                    {
                        head=b;
                    }else{
                        
                        prev->next=b;
                    }
                    
                    
                         a=head;
                        dummy->next=head;
                        prev=dummy;
                    //prev=dummy;
                   // a=head;
                    
                }else{
                    
                    prev=a;
                    a=a->next;
                }
            }
            
        }
        
        
        return dummy->next;
        
        
    }
};
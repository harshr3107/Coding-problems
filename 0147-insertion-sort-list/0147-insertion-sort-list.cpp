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
    
    void printlist(ListNode* head)
    {
        while(head!=NULL)
        {
            cout<<head->val<<" ";
            head=head->next;
        }
        cout<<endl;
    }
    
    
    ListNode* insertionSortList(ListNode* head) {
        
        if(head==NULL || head->next==NULL)
        {
            return head;
        }
        
        ListNode* temp = head;
        ListNode* tprev = NULL;
        ListNode* prev = head;
        ListNode* cur = head->next;
    
        
        
        while(cur!=NULL)
        {
            //printlist(head);
            //cout<<"i entered here for "<<cur->val<<" and prev is "<<prev->val<<endl;
            
            if(prev->val>cur->val)
            {
                //cout<<"i entered in first if\n";
                
                temp=head;
                
                prev->next=cur->next;
                
               if(cur->val<temp->val)
               {
                   cur->next=head;
                   head=cur;
                   temp=head;
                   
                   
               }else{
                   
                   tprev=head;
                   temp = head->next;
                   
                   while(temp->val<cur->val)
                   {
                       tprev=tprev->next;
                       temp=temp->next;
                   }
                   
                   cur->next=tprev->next;
                   tprev->next=cur;
                   
                   
               }
               
                prev=prev;
                cur=prev->next;
                
            }else{
                
                //cout<<"i entered in second if\n";
                
                prev=cur;
                cur=cur->next;
                
            }
            
            
            
        }
        
        
     return head;   
        
    }
};
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
        ListNode* prev=NULL;
        ListNode* curr = head;
        ListNode* nextt;
        
        while(curr!=NULL)
        {
            nextt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextt;
        }    
        
        
        return prev;
            
        
        
    }
    
    
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        int a=0;
        ListNode* dummy=new ListNode(-1);
        dummy->next=head;
        
        ListNode* prev=dummy;
        
        ListNode* temp=dummy;
        
        
        while(temp!=NULL)
        {
            cout<<"the temp ka data is "<<temp->val<<endl;
            
            a=0;
            while(temp!=NULL && a!=k)
            {
                temp=temp->next;
                a++;
            }
            
            ListNode* nextt;
            
            if(temp!=NULL)
            {
                
                
                nextt=temp->next;
                temp->next=NULL;
                
            }else{
                
                cout<<"i entered here\n";
                cout<<"val of a here is "<<a<<endl;
                
                if(a!=k+1)
                {
                    break;
                }
                
                 ListNode* newhead = reverse(prev->next);
             //   cout<<"yaha pe new head will be "<<newhead->val<<endl;
                
                prev->next=newhead;
                break;
                   
                nextt=NULL;
                temp=NULL;
            }
            
           
            ListNode* newhead = reverse(prev->next);
            
            if(newhead==NULL)
            {
                break;
            }
            
            cout<<"\nthe new heads is  "<<newhead->val<<endl<<endl;
            
            prev->next=newhead;
            
            if(prev->val==dummy->val)
            {
                dummy->next=newhead;
            }
            
            while(prev->next!=NULL)
            {
                prev=prev->next;
            }
            
            prev->next=nextt;
           
            temp=prev;
            
            
            
        }
        
        
        
        return dummy->next;
        
        
        
    }
};
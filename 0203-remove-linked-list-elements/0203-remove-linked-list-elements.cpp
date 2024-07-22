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
    ListNode* removeElements(ListNode* head, int val) {
        
        if(head==NULL)
        {
            return head;
        }
        
        ListNode* prev = new ListNode(-1);
        prev->next=head;
        ListNode* temp=head;
        
        while(temp!=NULL)
        {
            if(temp->val==val)
            {
                //cout<<"i entered here for!!! "<<temp->val<<" here value of prev is "<<prev->val<<endl;
                
                
                if(temp==head)
                {
                    temp=temp->next;
                    head=temp;
                    prev->next=head;
                    
                }else{
                    
                    prev->next=temp->next;
                    temp=temp->next;
                }
                
               
                
            }else{
                
              //  cout<<"i entered here for "<<temp->val<<" here value of prev is "<<prev->val<<endl;
                
                temp=temp->next;
                prev=prev->next;
            }
            
            
            
            
            
        }
            
        return head;
    }
};
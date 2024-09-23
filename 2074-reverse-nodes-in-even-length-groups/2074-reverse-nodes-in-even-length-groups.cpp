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
                prev = curr;
                curr = nextt;
            }
        
       // display(prev);
        
        
        return prev;
        
        
    }
    

    
    
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        
        
        ListNode* dummy = new ListNode(-1);
        dummy->next=head;
        
        int num=1;
        int a=0;
        
        ListNode* prev=dummy;
       
        ListNode* temp = dummy;
        
        
        while(temp->next!=NULL)
        {
            //cout<<"val of head "<<temp->val<<" and the val of num is "<<num<<" and val of a is "<<a<<endl;
            
            ListNode* p;
            while(temp!=NULL && a!=num)
            {
                p=temp;
                temp=temp->next;
                if(temp==NULL)
                {
                    temp=p;
                    break;
                }
                a++;
            }
            
            //cout<<"current val of a is "<<a<<endl;
            //cout<<"current val of temp is "<<temp->val<<endl;
            
            if(a%2==0)
            {
               ListNode* h = temp->next;
                
                temp->next=NULL;
                ListNode*  t = reversee(prev->next);
                
                prev->next=t;
                
                while(t->next!=NULL)
                {
                    t=t->next;
                }
                
                t->next=h;
                temp=t;
                
                
            }
            
            prev = temp;
            temp=prev;
            a=0;
            num++;
            
        }
        
        
        
        
        
        return head;
        
        
    }
};
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
    ListNode* swapPairs(ListNode* head) {
        
        
        int a=0;
        ListNode* prev;
        
        ListNode* temp = head;
        
        while(temp!=NULL)
        {
            
            //cout<<"the temp is "<<temp->val<<endl;
            
            ListNode* h = temp;
            a=0;
            
            if(h!=NULL && h->next!=NULL)
            {
               // cout<<"mai yaha aaya\n";
                
                ListNode* m = h->next->next;
                ListNode* a = h;
                ListNode* b = h->next;
                
                //cout<<"a is "<<a->val<<" b is "<<b->val<<endl;
                
                b->next=a;
                a->next=m;
                
               
                
                if(a==head)
                {
                    head=b;
                }else{
                    
                    prev->next=b;
                }
            
                prev=a;
                temp=m;
                continue;
                
                
            }
            
            
            
            temp=temp->next;
            
            
        }
        
        
        return head;
        
        
        
    }
};
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
    
    
    int findlen(ListNode* head)
    {
        ListNode* p = head;
        int a=0;
        while(p!=NULL)
        {
            a++;
            p=p->next;
        }
        
        
        return a;
    }
    
    
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        
        int h = findlen(head);
        vector<ListNode*> v;
        
        cout<<"value of h is "<<h<<endl;
        
        
        if(h<=k)
        {
            while(head!=NULL)
            {
                ListNode* temp = head;
                  head=head->next;
                temp->next=NULL;
              
               
                v.push_back(temp);
                k--;
                
                
            }
            
            
            while(k!=0)
            {
                v.push_back(NULL);
                k--;
            }
            
            
            
        }else{
            
            int mini = h/k;
            int extras = h%k;
            
            while(head!=NULL)
            {
                int a=1;
                ListNode* temp=head;
                while(a!=mini)
                {
                    temp=temp->next;
                    a++;
                }
                
                if(extras!=0)
                {
                    temp=temp->next;
                    extras--;
                }
                
                v.push_back(head);
                head=temp->next;
                temp->next=NULL;
                
                
                
            }
            
            
            
            
            
        }
        
        
        return v;
        
        
        
        
        
    }
};
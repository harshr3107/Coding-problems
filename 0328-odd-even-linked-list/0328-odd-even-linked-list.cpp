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
    ListNode* oddEvenList(ListNode* head) {
        
        ListNode* oddlist=NULL;
        ListNode* tempe;
        ListNode* evenlist = NULL;
        ListNode* tempo;
        int a=0;
        
        while(head!=NULL)
        {
            ListNode* n = new ListNode(head->val);
            a++;
            
            if((a&1)==0)
            {
               //cout<<"i am even "<<n->val<<endl;
                //even;
                if(evenlist==NULL)
                {
                    evenlist=n;
                    tempe=evenlist;
                    
                }else{
                    
                    tempe->next=n;
                    tempe=tempe->next;
                    
                    
                }
            }else{
                
                if(oddlist==NULL)
                {
                    oddlist=n;
                    tempo=oddlist;
                    
                }else{
                    
                    tempo->next=n;
                    tempo=tempo->next;
                    
                    
                }
                
                
            }
            
            head=head->next;
        }
        
        
        
        if(oddlist==NULL)
        {
            return evenlist;   
        }
        if(evenlist==NULL)
        {
            return oddlist;
        }
        
        
        tempo->next=evenlist;
        
        
        return oddlist;
        
        
        
        
    }
};
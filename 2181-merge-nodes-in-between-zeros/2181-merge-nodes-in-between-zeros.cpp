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
    ListNode* mergeNodes(ListNode* head) {
        
        
        ListNode* prev = head;
        ListNode* a = head->next;
        int sum=0;
        
        while(a!=NULL)
        {
            
            
            if(a->val==0)
            {
                
                if(sum!=0)
                {
                     ListNode* temp = new ListNode(sum);
                    temp->next=a->next;
                     prev->next=temp;
                    prev=temp;
                    
                }
                
                a=a->next;
                
                if(a==NULL)
                {
                    continue;
                }
                
               
                  sum=0;
                
                
                
            }
            
            
            
            
            sum+=a->val;
            a=a->next;
            
            
        }
        
        
       return head->next;
        
        
    }
};
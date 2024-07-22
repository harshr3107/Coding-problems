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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        
        map<int,int> m;
        
        for(int i=0;i<nums.size();i++)
        {
            m[nums[i]]++;
        }
        
        ListNode* prev = new ListNode(-1);
        prev->next=head;
        ListNode* temp = head;
        
        while(temp!=NULL)
        {
            if(m.find(temp->val)!=m.end())
            {
                //cout<<"i entered here for "<<temp->val<<endl;
                
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
                
                prev=prev->next;
                temp=temp->next;
                
            }
            
        }
        
        
        return head;
        
        
    }
};
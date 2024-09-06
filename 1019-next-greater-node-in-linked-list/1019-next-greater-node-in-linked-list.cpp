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
    
    ListNode* reverselinkedlist(ListNode* head)
    {
        ListNode* prev = NULL;
        ListNode* curr=head;
        ListNode* next;
        
        
        
        while(curr!=NULL)
        {
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
            
        }
        
        
        return prev;
        
    }
    
    
    
   /* void display(ListNode* head)
    {
        while(head!=NULL)
        {
            cout<<head->val<<" ";
            head=head->next;
        }
        
        cout<<endl;
    }*/
    
    
    
    vector<int> nextLargerNodes(ListNode* head) {
        
        //display(head);
        head = reverselinkedlist(head);
        //display(head);
        
        vector<int> nextgreater;
        nextgreater.push_back(0);
        
        stack<int> st;
        st.push(-1);
        st.push(head->val);
        
        head=head->next;
        
        
        while(head!=NULL)
        {
            while(st.top()!=-1 && st.top()<=head->val)
            {
                st.pop();
            }
            
            if(st.top()==-1)
            {
                nextgreater.push_back(0);
            }else{
                
                nextgreater.push_back(st.top());
                
            }
            
            st.push(head->val);
            
            head=head->next;
            
        }
        
        reverse(nextgreater.begin(),nextgreater.end());
        
        return nextgreater;
        
    }
};
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
    
    void getnextgreater(vector<int> v,vector<int>& nextgreater)
    {
        stack<int> st;
        int n = v.size();
        
        nextgreater[n-1]=-1;
        st.push(-1);
        st.push(v[n-1]);
        
        for(int i=n-2;i>=0;i--)
        {
            
            while(st.top()!=-1 && v[i]>=st.top())
            {
                st.pop();
            }
            
            
            nextgreater[i]=st.top();
            st.push(v[i]);
            
        }
        
        
        
        
    }
    
    
    
    
    
    ListNode* removeNodes(ListNode* head) {
        
        
        vector<int> v;
        
        
        while(head!=NULL)
        {
            v.push_back(head->val);
            head=head->next;
        }
        
        
        vector<int> nextgreater(v.size());
        
        getnextgreater(v,nextgreater);
        ListNode* nex;
        
        for(int i=0;i<nextgreater.size();i++)
        {
            //cout<<nextgreater[i]<<" ";
            
            if(nextgreater[i]==-1)
            {
                ListNode* temp = new ListNode(v[i]);
                
                if(head==NULL)
                {
                    head=temp;
                    nex=head;
                }else{
                    
                    nex->next=temp;
                    nex=nex->next;
                    
                }
                
            }
           
        }
        
        
        
        
        return head;
        
        
        
    }
};
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
    
    void getnode(ListNode* head,vector<int>& v)
    {
        while(head!=NULL)
        {
            v.push_back(head->val);
            head=head->next;
        }
        
    }
    
    
    
    int pairSum(ListNode* head) {
        
       vector<int> v;
       getnode(head,v);
        priority_queue<int> maxheap;
        
        
        int i=0;
        int size = v.size();
        int j=size-1;
        
        while(i<=((size/2)-1) && j>i)
        {
            maxheap.push(v[i]+v[j]);
            i++;
            j--;
        }
        
        return maxheap.top();
        
        
    }
};
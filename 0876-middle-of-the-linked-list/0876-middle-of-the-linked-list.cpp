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
    ListNode* middleNode(ListNode* head) {
        
        ListNode* p = head;
        ListNode* q = head;
        int a=0;
        
        while(p!=NULL)
        {
            a++;
            if(a%2==0)
            {
                q=q->next;
            }
            p=p->next;
        }
        
        
        return q;
        
    }
};
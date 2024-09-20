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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        
        ListNode* head2 = list2;
        ListNode* tail2 = list2;
        
        while(tail2->next!=NULL)
        {
            tail2=tail2->next;
        }
        
        
        int count=1;
        ListNode* temp = list1;
        
        while(count!=a)
        {
            temp=temp->next;
            count++;
        }
        
        ListNode* nex = temp->next;
        temp->next=head2;
        
        while(count!=b)
        {
            nex=nex->next;
            count++;
        }
        
        
        tail2->next=nex->next;
        
        
        
       
        
        
        
        return list1;
        
    }
};
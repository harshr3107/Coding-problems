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
    ListNode* rotateRight(ListNode* head, int k) {
        
        
        if(k==0 || head==NULL)
        {
            return head;
        }
        
        
        ListNode* temp = head;
        int length=0;
        
        while(temp!=NULL)
        {
            length++;
            temp=temp->next;
        }
        
        k = k%length;
        
       // cout<<"balue of length is "<<length<<endl;
        //cout<<"value of k is "<<k<<endl;
        
        int h = length-k;
        
        //cout<<"value of h is "<<h<<endl;
        
        int i=1;
        temp=head;
        
        while(i<h)
        {
            i++;
            temp=temp->next;
            
        }
        
        if(temp->next==NULL)
        {
            return head;
        }
        
        ListNode* temp2 = temp->next;
        temp->next=NULL;
        ListNode* temp3 = temp2;
        
        while(temp2->next!=NULL)
        {
            temp2=temp2->next;
        }
        
        temp2->next=head;
        head=temp3;
        
        return head;
        
        
        
        
    }
};
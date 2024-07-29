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
    ListNode* swapNodes(ListNode* head, int k) {
        
        ListNode* headans = new ListNode(-1);
        headans->next=head;
        ListNode* pcur = head;
        ListNode* pprev = new ListNode(-1);
        pprev->next=pcur;
        ListNode* qcur = head;
        ListNode* qprev = new ListNode(-1);
        qprev->next=qcur;
        ListNode* r = head;
        int i=0;
        
        
        while(i!=k)
        {
            i++;
            r=r->next;
            
            if(i!=k)
            {
            pcur=pcur->next;
            pprev=pprev->next;
            }
        }
        
       // cout<<"value of r is "<<r->val<<endl;
        
        
        while(r!=NULL)
        {
            r=r->next;
            qcur=qcur->next;
            qprev=qprev->next;
        }
        
        /*cout<<"value of qcur is "<<qcur->val<<endl;
         cout<<"value of qpre is "<<qprev->val<<endl;
        cout<<"value of pcur is "<<pcur->val<<endl;
         cout<<"value of ppre is "<<pprev->val<<endl;*/
        
         ListNode* temp;
        
       if(qcur==pcur)
        {
            return head;
        }else if(pcur->next==qcur)
       {
           
           temp=qcur->next;
           pprev->next=qcur;
           qcur->next=pcur;
           pcur->next=temp;
           
        }else if(qcur->next==pcur)
       {
       
            temp=pcur->next;
            qprev->next=pcur;
            pcur->next=qcur;
           qcur->next=temp;
       
       
       }else{
        
        
           //cout<<"i entered here\n";
          temp = qcur->next;
           pprev->next=qcur;
           qcur->next=pcur->next;
           qprev->next=pcur;
           pcur->next=temp;
            
        }
        
        
        
        if(pprev->val==-1)
        {
            return pprev->next;
        }
        
        
        if(qprev->val==-1)
        {
            return qprev->next;
        }
        
        return headans->next;
        
        
        
        
        

        
        //solve forwar here
       
        
    
        
        
    }
};
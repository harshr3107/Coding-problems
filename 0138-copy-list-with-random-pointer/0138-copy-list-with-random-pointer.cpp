/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        map<Node*,Node*> m;
        
        Node* temphead = head;
        
        if(head==NULL)
        {
            return NULL;
        }
        
        Node* l2=NULL;
        Node* temp=l2;
        
        while(head!=NULL)
        {
            Node* n = new Node(head->val);
            
            if(l2==NULL)
            {
                l2=n;
                temp=l2;
                m[head]=l2;
                
            }else{
                
                
                temp->next=n;
                temp=temp->next;
                m[head]=temp;
            }
            
           head=head->next; 
        }
        
        
        temp=l2;
        
        while(temphead!=NULL)
        {
            temp->random=m[temphead->random];
            temp=temp->next;
            temphead=temphead->next;
        }
        
        return l2;
        
    }
};


/*

MY FIRST INTUTION
here i didnot read the question properly and tried to change value insted of nodes

*/
class Solution {
public:
    
    void getorder(ListNode* head,vector<int>& v)
    {
        while(head!=NULL)
        {
            v.push_back(head->val);
            head=head->next;
        }
    }
    
    
    void display(ListNode* head)
    {
         while(head!=NULL)
        {
            cout<<head->val<<" ";
            head=head->next;
        }
        
        cout<<endl;
    }
    
    
    
    
    void reorderList(ListNode*& head) {
        
        vector<int> v;
        getorder(head,v);
        
        
        int i=0;
        int j = v.size()-1;
        ListNode* current = new ListNode(-1);
        ListNode* c = NULL;
        
        current->next=c;
        
        while(j>i)
        {
            //cout<<"i entered here for i and j "<<i<<" "<<j<<endl;
            
            ListNode* a = new ListNode(v[i]);
            ListNode* b = new ListNode(v[j]);
            
            a->next=b;
            
            if(c==NULL)
            {
                //cout<<"i entered here\n";
                current=a;
                c=b;
                
            }else{
                
                //cout<<"mai aab yaha aaya\n";
                c->next=a;
                c=b;
            }
            
            i++;
            j--;
            
           
            
            
        }
        
            if(i==j)
            {
                //cout<<"idher aana nahi pada\n";
                 ListNode* a = new ListNode(v[j]);
                if(c==NULL)
                {
                    current=a;
                }else{
                    c->next=a;
                }
                
            }
        
       
         head->next=current->next;
         //head=head->next;
         //current;
        
         
        // ListNode* p =cuuernt;
        
        //display(head);
        
        
        
    }
};



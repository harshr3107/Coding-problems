

class node
{
    public:
    
    int data;
    node* prev;
    node* next;
    
    
    node(int d)
    {
        data=d;
        prev=NULL;
        next=NULL;
    }
    
};




class LRUCache {
public:
    
    
    node* head;
    node* cur;
    unordered_map<int,node*> mp1;
    unordered_map<int,int> mp2;
    int size;
    int csize;
    
    
    
    
    LRUCache(int capacity) {
        
        size=capacity;
        csize=0;
        head=NULL;
        cur=NULL;
        
    }
    
    
    
    void deleteprevandaddnew(int key)
    {
        
        if(cur->data==key)
        {
            return;
        }
        
        if(head->data==key)
        {
            node* temp = head;
            head=head->next;
            head->prev=NULL;
            
            
            mp1[head->data]=head;
            
            
            cur->next=temp;
            temp->prev=cur;
            temp->next=NULL;
            
            mp1[cur->data] = cur;
            cur=temp;
            mp1[cur->data]=cur;
            
            return;
            
        }
        
        
        
        
        node* h = mp1[key];
        
        node* previous = h->prev;
        node* nextt = h->next;
        
        previous->next=nextt;
        nextt->prev=previous;
        
        mp1[previous->data]=previous;
        mp1[nextt->data] = nextt;
        
        cur->next= h;
        h->prev=cur;
        
        mp1[cur->data]=cur;
        cur=h;
        mp1[cur->data]=cur; 
        
        
        
        
    }
    
    
    
    int get(int key) {
        
        
        if(mp2.count(key))
        {
            
            deleteprevandaddnew(key);
            
            return mp2[key];
            
        }
        
        
        return -1;
        
        
        
    }
    
    
    
    
    
    
    void put(int key, int value) {
        
        //cout<<"mia put mai aaya "<<key<<"dalne ke liye and mera csize is "<<csize<<endl;
        
        if(head==NULL)
        {
            //cout<<"mai yaha pe aagaya jab khali hai listn\n";
            csize++;
            mp2[key]=value;
            node* temp = new node(key);
            head=temp;
            cur=temp;
            
            mp1[key] = temp;
            
            return;
        }
        
        
        
        if(mp2.count(key))
        {
            //cout<<"mai already exist karta hoon\n";
            
            deleteprevandaddnew(key);
            mp2[key]=value;
           
            
            return;
            
        }
        
        mp2[key]=value;
        
        if(csize>=size)
        {
            //cout<<"mere wajah se lru kp delete hona padega yaha pe head hai "<<head->data<<endl;
            
            node* temp = head;
            mp2.erase(temp->data);
            mp1.erase(temp->data);
            
            head=head->next;
            
            if(head==NULL)
            {
                //cout<<"mujhe pehle khali hona pada\n";
                csize--;
               
            }else{          
             head->prev=NULL;
            
            
            //cout<<"naya head hai "<<head->data<<" and cur is "<<cur->data<<endl;
            
            mp1[head->data]=head;
            csize--;
            }
        }
        
        
        csize++;
        
         if(head==NULL)
        {
            //cout<<"mai yaha pe aagaya kyuki wapas khali hogaya\n";
            csize++;
            mp2[key]=value;
            node* temp = new node(key);
            head=temp;
            cur=temp;
            
            mp1[key] = temp;
             
             // cout<<"naya head hai "<<head->data<<" and cur is "<<cur->data<<endl;
            
            return;
        }
       
        
        
        
       
        node* temp = new node(key);
        node* crnt = mp1[cur->data];
        
        crnt->next=temp;
        temp->prev=crnt;
        
        mp1[cur->data] = crnt;
        cur=temp;
        mp1[cur->data] = cur;
        
        // cout<<"naya head hai "<<head->data<<" and cur is "<<cur->data<<endl;
        
        return;
        
        
        
        
        
        
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
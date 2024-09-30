class node{
    
    public:
    
    int data;
    node* next;
    
        node(int d)
        {
            data=d;
            next=NULL;
        }
    
};



class CustomStack {
public:
    
    node* top;
    node* bottom;
    int csize;
    int size;
    
    
    CustomStack(int maxSize) {
        
        cout<<"size of the stack is "<<maxSize<<endl;
        top=NULL;
        bottom=NULL;
        csize=0;
        size=maxSize;
        
        
        
    }
    
    void push(int x) {
        
        cout<<x<<" ko push kar rahe\n"; 
        
        if(csize==size)
        {
            return;
        }
        
        node* temp = new node(x);
        
        if(csize==0)
        {
            cout<<"mai yaha kuch bhi nahi waha enter hogaya\n";
            top=temp;
            bottom=temp;
            csize++;
            return;
        }
        
        
        //head ko add kar rahe hai just feel that
        
        temp->next=top;
        top=temp;
        
       
        
        csize++;
        
        
        
    }
    
    int pop() {
        
        
        cout<<"mai nikalne aaya\n";
        
        if(csize==0)
        {
            return -1;
        }
        
        int d = top->data;
        top=top->next;
        csize--;
        
        cout<<d<<" ko nikal diya\n";
        
        //cout<<"naya top hai "<<top->data<<" "<<"naya bottom hai "<<bottom->data<<endl;
        
        return d;
        
        
    }
    
    
    void display(node* d)
    {
        while(d!=NULL)
        {
            cout<<d->data<<" ";
            d=d->next;
        }
        
        cout<<endl;
        
    }
    
    void increment(int k, int val) {
        
        if(csize==0)
        {
            return;
        }
        
        int i=0;
        
        node* temp1 = top;
        node* temp2 = top;
        
        while(temp2!=NULL && i!=k)
        {
            temp2=temp2->next;
            i++;
        }
        
        while(temp2!=NULL)
        {
            temp2=temp2->next;
            temp1=temp1->next;
        }
        
        while(temp1!=NULL)
        {
            temp1->data+=val;
            temp1=temp1->next;
            
        }
        
       
        
        display(top);
        
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
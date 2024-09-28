class node
{
    public:
    int data;
    node* next;
    
    node(int d)
    {
        data=d;
        next=NULL;
    }
    
};





class MyCircularDeque {
public:
    
    node* head;
    node* tail;
    int size;
    int cursize;
    
    
    
    MyCircularDeque(int k) {
        
        size=k;
        cursize=0;
        
    }
    
    bool insertFront(int val) {
        
        if(cursize==size)
        {
            return false;
        }
        
        node* temp = new node(val);
        
        
        if(cursize==0)
        {
            head=temp;
            tail=temp;
            cursize++;
            return true;
            
        }
        
        
        temp->next=head;
        head=temp;
        tail->next=head;
        cursize++;
        return true;
        
        
        
    }
    
    bool insertLast(int val) {
        
        if(cursize==size)
        {
            return false;
        }
        
       
        
        node* temp = new node(val);
        
        if(cursize==0)
        {
            head=temp;
            tail=temp;
            cursize++;
            return true;
        }
        
        tail->next=temp;
        tail=temp;
        tail->next=head;
        
        cursize++;
        
        return true;
        
        
        
    }
    
    bool deleteFront() {
        
        if(cursize==0)
        {
            return false;
        }
        if(cursize==1)
        {
            head=NULL;
            tail=NULL;
            cursize--;
            return true;
        }
        
        cursize--;
        
        head=head->next;
        tail->next=head;
        
        return true;
        
        
        
        
    }
    
    
    bool deleteLast() {
        
        
        if(cursize==0)
        {
            return false;
        }
        
        if(cursize==1)
        {
            head=NULL;
            tail=NULL;
            cursize--;
            return true;
        }
        
        
        //cout<<"the current head is "<<head->data<<" and current tail is "<<tail->data<<endl;
        
        node* temp = head;
        
        while(temp->next!=tail)
        {
            temp=temp->next;
            
        }
        
        tail=temp;
        temp->next=head;
        
        cursize--;
       
        
        
        
        return true;
        
        
        
        
        
        
    }
    
    int getFront() {
        
        if(cursize==0)
        {
            return -1;
        }
        
        return head->data;
        
    }
    
    int getRear() {
        
        if(cursize==0)
        {
            return -1;
        }
        
        return tail->data;
        
    }
    
    bool isEmpty() {
        
        if(cursize==0)
        {
            return true;
        }
        
        return false;
        
       
        
    }
    
    bool isFull() {
        
        if(cursize==size)
        {
            return true;
        }
        
        return false;
        
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
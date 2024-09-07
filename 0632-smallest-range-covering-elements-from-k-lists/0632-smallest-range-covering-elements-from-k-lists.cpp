class Solution {
public:
    
    class node{
        
        public:
        
        int data;
        int i;
        int j;
        
        node(int d,int row,int col)
        {
            data=d;
            i=row;
            j=col;
        }
        
        
        
    };
    
    
    class compare 
    {
        public:
        
        bool operator()(node* a,node* b)
        {
            return a->data>b->data;
        }
        
    };
    
    
    
    vector<int> smallestRange(vector<vector<int>>& nums) {
      
        priority_queue<node*,vector<node*>,compare> minheap;
        int max=INT_MIN;
        
        
        for(int i=0;i<nums.size();i++)
        {
            node* temp = new node(nums[i][0],i,0);
            minheap.push(temp);
            if(max<nums[i][0])
            {
                max=nums[i][0];
            }
            
        }
        
        
        
        vector<int> v;
        v.push_back(minheap.top()->data);
        v.push_back(max);
        
        int mindiff = max-minheap.top()->data;
        
        
        while(!minheap.empty())
        {
            node* temp = minheap.top();
            minheap.pop();
            
            int i = temp->i;
            int j = temp->j;
            
            if((j+1)<nums[i].size())
            {
                node* n = new node(nums[i][j+1],i,j+1);
                if(max<nums[i][j+1])
                {
                    max=nums[i][j+1];
                }
                minheap.push(n);
                
                
                if(mindiff>(max-(minheap.top()->data)))
                {
                    mindiff = max-(minheap.top()->data);
                    v.clear();
                    v.push_back(minheap.top()->data);
                    v.push_back(max);
                }
                
                
            }else{
                break;
            }
            
            
            
        }    
            
        
        
        
        return v;
        
        
        
    }
};
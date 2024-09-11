class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        
        
        priority_queue<int,vector<int>,greater<int>> minheap1;
        priority_queue<int,vector<int>,greater<int>> minheap2;
        
        
        int i=0;
        
        while(i<candidates)
        {
            minheap1.push(costs[i]);
            i++;
        }
        
        int j=costs.size()-1;
        i=i-1;
        int a=0;
        
        while(j>=0 && j>i && a<candidates)
        {
            minheap2.push(costs[j]);
            j--;
            a++;
        }
        
        j=j+1;
        //int c=0;
        long long anscost=0;
        
    
        
        
        for(int l=0;l<k;l++)
        {
            
            if(minheap1.empty())
            {
                anscost+=minheap2.top();
                minheap2.pop();
                if((j-1)>i)
                {
                    j=j-1;
                    minheap2.push(costs[j]);
                }
            }else if(minheap2.empty())
            {
                anscost+=minheap1.top();
                minheap1.pop();
                if((i+1)<j)
                {
                    i=i+1;
                    minheap1.push(costs[i]);
                }
                
                
            }else{
                
                if(minheap1.top()<=minheap2.top())
                {
                  anscost+=minheap1.top();
                  minheap1.pop();
                   if((i+1)<j)
                   {
                    i=i+1;
                    minheap1.push(costs[i]);
                   }
                    
                }else{
                    
                 anscost+=minheap2.top();
                minheap2.pop();
                if((j-1)>i)
                {
                    j=j-1;
                    minheap2.push(costs[j]);
                }
                    
                    
                    
                }
                
                
                
                
            }
            
            
        }
        
        
        return anscost;
            
        
        
        
        
        
    }
};
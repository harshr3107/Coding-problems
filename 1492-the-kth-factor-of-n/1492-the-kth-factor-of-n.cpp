class Solution {
public:
    int kthFactor(int n, int k) {
        
       int h=0;
        
        for(int i=1;i<=n/2;i++)
        {
            if(n%i==0)
            {
                h++;
                
                if(h==k)
                {
                    return i;
                }
            }
            
            
        }
        
        if(h+1==k)
        {
            return n;
        }
        
        
        return -1;
        
        
        
    }
};
class Solution {
public:
    
    
   
    
    
    
    
    double myPow(double x, int n) {
        
        if (n == INT_MAX) return (x == 1) ? 1 : (x == -1) ? -1 : 0;
        if (n == INT_MIN) return (x == 1 || x == -1) ? 1 : 0;
       
        if(x==0)
        {
            return x;
        }
        
        if(n==0)
        {
            return 1.0;
        }else if(n>0)
        {
            return x*myPow(x,n-1);
        }
        
        return (1/x)*myPow(x,n+1);
        
       // return 0;
        
    }
};
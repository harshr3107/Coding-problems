class Solution {
public:
    int mySqrt(int x) {
        
        if(x==1)
        {
            return 1;
        }
  
        int low=1;
        int high=x-1;
        long long mid=0;
        long long ans=0;
        
        while(high>=low)
        {
            mid = low+(high-low)/2;
            
           if(mid*mid<=x)
           {
               ans=mid;
               
               low=mid+1;
               
           }else{
                
               high=mid-1;
           }
            
            
            
            
        }
        
        return ans;
        
        
        
        
       /*BRUTE FORCE APPROCH 
       
       long long a=1;
        
        while(a*a < pow(2,31)-1 && a*a<=x)
        {
            a++;
        }
        
        return a-1;
        */
        
          
        
        
    }
};
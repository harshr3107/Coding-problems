class Solution {
public:
    int mySqrt(int x) {
        
        long long a=1;
        
        while(a*a < pow(2,31)-1 && a*a<=x)
        {
            a++;
        }
        
        return a-1;
        
          
        
        
    }
};
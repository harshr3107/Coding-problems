class Solution {
public:
    bool isPowerOfFour(int n) {
        
        int a=0;
        
        while(n>0)
        {
            a++;
             if((n&1)==1)
             {
                // cout<<"value of a is "<<a<<endl;
                 n=(n>>1);
                 
                 //cout<<"value of n is "<<n<<endl;
                 
                if(n!=0)
                {
                    return false;
                }
             }
            
            n=(n>>1);
            
        }
        
        if(a!=0 && (a&1)==1)
        {
            return true;
        }
        
        return false;
        
        
    }
};
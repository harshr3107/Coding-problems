class Solution {
public:
    bool isPowerOfTwo(int n) {
        
        
        
        while(n>0)
        {
            cout<<"value of n is "<<n<<endl;
            if((n&1)==1)
            {
                if(n>>1==0)
                {
                    return true;
                }else{
                    
                    return false;
                }
            }
            
            n=n>>1;
            
        }
        
        return false;
    }
};
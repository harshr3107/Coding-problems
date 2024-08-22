class Solution {
public:
    int findComplement(int num) {
        
        int ans=0;
        string s="";
        
        long long a=1;
        
        while(num>0)
        {
            int digit = (num&1);
            
            if(digit==0)
            {
                
                ans=ans+1*a;
                
            }
            
            a=a*2;
            num=(num>>1);
            
        }
        
       
        return ans;
        
        
    }
};
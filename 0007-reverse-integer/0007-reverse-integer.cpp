class Solution {
public:
    int reverse(int x) {
        
        cout<<x<<endl;
        signed int digit;
        long long ans=0;
        int minus=0;
        string a = to_string(x);
        if(a[0]=='-')
        {
            minus++;
            
        }
        
        x=abs(x);
        
        
        
        while(x>0)
        {
            digit= x%10;
            ans=ans*10+digit;
            x/=10;
            
        }   
        
        if(ans>pow(2,31)-1)
        {
            return 0;
        }
        
        if(minus)
        {
        return -ans;
        }
        
        return ans;
        
    }
};
class Solution {
public:
    
    
int find1s(long long n)
{
    long long p=1;
    long long a=1;
    
    while(p<=n)
    {
        p=p*2;
        a++;
    }
    
    a--;
    p=p/2;
    
    int ans=0;
    
    while(a>0)
    {
        int digit = n/p;
        n=n-p*digit;
        ans = ans+(digit&1);
        p=p/2;
        a--;
    }
    
    return ans;
    
}
    
    
    int hammingWeight(long long n) {
        
      int  a = find1s(n);
        
      return a;
        
    }
};
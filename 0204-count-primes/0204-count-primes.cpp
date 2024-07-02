class Solution {
public:

    
    
    
    int countPrimes(int n) {
        
        int ans=0;
        
        vector<bool> prime(n+1,true);
       prime[0]=false;
        prime[1]=false;
        
        
        for(int i=2;i<n;i++)
        { 
            if(prime[i]==false)
            {
                continue;
            }
            
            if(prime[i])
            {
                ans++;
                
                int j=i;
                int a=2;
                
                while(j<=n)
                {
                    //cout<<"value of j is "<<j<<endl;
                    prime[j]=false;
                    j=i*a;
                    a++;
                    
                }
            }
            
            
            
        }
    
       
        
        return ans;
        
    }
};
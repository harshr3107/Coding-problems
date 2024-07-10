class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
       
        int mod = 1e9+7;
      int  sum=0;
      int  evencount=0;
        int oddcount=0;
        int ans=0;
        
        
        for(int i=0;i<arr.size();i++)
        {
            sum+=arr[i];
            if((sum%2)==0)
            {
                evencount++;
                ans=(ans+oddcount)%mod;
                
                
            }else{
                
                ans++;
                oddcount++;
                ans=(ans+evencount)%mod;
                
                
            }
        }
        
        
       
                   
                 return ans%mod;
        
    }
};
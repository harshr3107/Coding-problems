class Solution {
public:
    
    
    int getclimbstairs(int n,vector<int>& dp)
    {
         if(n<=0)
        {
            return 0;
        }
        
        if(n==1 || n==2)
        {
            return n;
        }
        
        
        if(dp[n]!=-1)
        {
            return dp[n];
        }
        
        
        
        int f1 = getclimbstairs(n-1,dp);
        int f2 = getclimbstairs(n-2,dp);
        
        dp[n]=f1+f2;
        
        return f1+f2;
        
    }
  
    
    
    int climbStairs(int n) {
        
        vector<int> dp(n+1,-1);
        
        return getclimbstairs(n,dp);        
        
       
    }
};
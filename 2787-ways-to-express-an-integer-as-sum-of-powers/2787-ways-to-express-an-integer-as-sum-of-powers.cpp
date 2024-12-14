class Solution {
public:
    
    
    int getways(int tsum,int i,int x,vector<vector<int>>& dp)
    {
      
        
        
        int mod = 1e9+7;
        
        if(tsum==0)
        {
            return 1;
        }
        
        if(i<=0)
        {
            return 0;
        }
        
        if(dp[tsum][i]!=-1)
        {
            return dp[tsum][i];
        }
        
        int take=0;
        if(tsum-pow(i,x)>=0)
        {
            take = getways(tsum-pow(i,x),i-1,x,dp);
        }
        
          int nottake = getways(tsum,i-1,x,dp);
        
        dp[tsum][i] = (take+nottake)%mod;
        
        return dp[tsum][i];
    }
    
    
    
    int numberOfWays(int n, int x) {
        
        int h = 4;
        
       
        
         int a = ceil(pow(static_cast<float>(n),1.0/x));
        
        vector<vector<int>> dp(n+1,vector<int>(a+1,-1));
        
        return getways(n,a,x,dp);
        
      
        
    }
};
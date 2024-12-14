class Solution {
public:
    
    
    int getmin(int i,int n,vector<vector<int>>& dp)
    {
        if(n==0)
        {
            return 0;
        }
        
        if(i<=0)
        {
            return 1e9+7;
        }
        
        if(dp[i][n]!=-1)
        {
            return dp[i][n];
        }
        
        int take = 1e9+7;
        
        if(n-pow(i,2)>=0)
        {
            take=1+getmin(i,n-pow(i,2),dp);
        }
        
        //cout<<"val of i = "<<i<<" and n = "<<n<<endl;
        
        int nottake = getmin(i-1,n,dp);
        
        dp[i][n]=min(take,nottake);
        return dp[i][n];
        
        
    }
    
    
    int numSquares(int n) {
        
        /*
         int i=ceil(sqrt(n));
         vector<vector<int>> dp(i+1,vector<int>(n+1,-1));
        
        return getmin(i,n,dp);*/
        
        
        int sqr=floor(sqrt(n));
        
         vector<vector<int>> dp(sqr+1,vector<int>(n+1,INT_MAX));
        
        for(int k=0;k<=sqr;k++)
        {
            dp[k][0]=0;
        }
        
       
        
        
         for(int i=1;i<=sqr;i++)
         {
             for(int j=0;j<=n;j++)
             {
                 
                 
                 
                 int take = 1e9+7;
        
                 if(j-pow(i,2)>=0)
                 {
                    take=1+dp[i][j-pow(i,2)];
                  }
        
       // cout<<"val of i = "<<i<<" and n = "<<n<<endl;
        
        int nottake = dp[i-1][j];
        
        dp[i][j]=min(take,nottake);
                 
                 //cout<<dp[i][j]<<" ";
                 
                 
                 
             }
             
             //cout<<endl;
         }
         
        
        return dp[sqr][n];
         
       
        
    }
};
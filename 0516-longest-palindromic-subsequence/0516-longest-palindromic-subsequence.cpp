class Solution {
public:
    
    
   /* int getlongest(string s,int ind1,int ind2,vector<vector<int>>& dp)
    {
        
        if(ind1>ind2)
        {
            return 0;
        }
        
        
        if(dp[ind1][ind2]!=-1)
        {
            return dp[ind1][ind2];
        }
        
        
        if(ind1==ind2)
        {
            return 1+getlongest(s,ind1+1,ind2-1,dp);
            
        }
        
        
        
        
        if(s.at(ind1)==s.at(ind2))
        {
            return 2+getlongest(s,ind1+1,ind2-1,dp);
        }
        
        int takeleft = getlongest(s,ind1+1,ind2,dp);
        int takeright = getlongest(s,ind1,ind2-1,dp);
        
        dp[ind1][ind2]=max(takeleft,takeright);
        
        return dp[ind1][ind2];        
        
    }
    
    */
    
    
    
    
    int longestPalindromeSubseq(string s) {
        
        if(s.length()==1)
        {
            return 1;
        }
     
        
       
        
        vector<vector<int>> dp(s.length()+2,vector<int>(s.length()+2,0)); 
        
        int ans=0;
        
        for(int i=1;i<=s.length();i++)
        {
            for(int j=s.length();j>=i;j--)
            {
                if(i==j)
                {
                    //cout<<"mai yaha aaya \n";
                    dp[i][j]=1+dp[i-1][j+1];
                     ans=max(ans,dp[i][j]);
                    continue;
                }
                
                if(s.at(i-1)==s.at(j-1))
                {
                    dp[i][j]=2+dp[i-1][j+1]; 
                    ans=max(ans,dp[i][j]);
                    continue;
                }
                
                int a = dp[i-1][j];
                int b = dp[i][j+1];
                
                dp[i][j]=max(a,b);
                
                
                
                
                
            }
            
            
        }
            
        
        return ans;
       
    }
};
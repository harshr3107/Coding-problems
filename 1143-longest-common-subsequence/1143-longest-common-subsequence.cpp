class Solution {
public:
    
    
    
    int getlongest(string& t1,string& t2,int ind1,int ind2,vector<vector<int>>& dp)
    {
        if(ind1>=t1.length() || ind2>=t2.length())
        {
            return 0;
        }
        
        
        if(dp[ind1][ind2]!=-1)
        {
            return dp[ind1][ind2];
        }
        
        
        if(t1.at(ind1)==t2.at(ind2))
        {
            return 1+getlongest(t1,t2,ind1+1,ind2+1,dp);
        }
        
        
        int f=0;
        
        if(ind1+1<t1.length())
        {
         f = getlongest(t1,t2,ind1+1,ind2,dp);
        }
        
        int s=0;
        
        if(ind2+1<t2.length())
        {
          s = getlongest(t1,t2,ind1,ind2+1,dp);
        }
        
        
        dp[ind1][ind2]=max(f,s);
        
        return dp[ind1][ind2];
        
        
    }
    
    
    
    
    
    
    
    
    
    
    int longestCommonSubsequence(string t1, string t2) {
        
        int ind1=t1.size();
        int ind2 = t2.size();
        
        vector<vector<int>> dp(ind1+1,vector<int>(ind2+1,-1));
        
        
        /*
        for(int i=1;i<=ind1;i++)
        {
            
            for(int j=1;j<=ind2;j++)
            {
                if(t1.at(i-1)==t2.at(j-1))
                {
                    dp[i][j]=1+dp[i-1][j-1];
                    continue;
                }
                
                int f = dp[i-1][j];
                int s = dp[i][j-1];
                
                
                dp[i][j] = max(f,s);
                
                
            }
            
        }
        
      
        return dp[ind1][ind2];*/
        
        
        return getlongest(t1,t2,0,0,dp);
        
        
    }
};
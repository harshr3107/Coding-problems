class Solution {
public:
    int minInsertions(string s) {
        
        vector<vector<int>> dp(s.length()+3,vector<int>(s.length()+3,0));
        
        int ans=INT_MIN;
        
         for(int i=1;i<=s.length();i++)
        {
            
            for(int j=s.length();j>=i;j--)
            {
                
                 if(i==j)
                {
                    
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
        
        return s.length()-ans;
        
        
        
        
    }
};
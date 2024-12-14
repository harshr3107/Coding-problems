class Solution {
public:
    
    bool checkpossible(string s1,string s2,string s3,int i,int j,int k,vector<vector<vector<int>>>& dp)
    {
        
        
        if(k==s3.length())
        {
            dp[i][j][k]=true;
            return true;
        }
        
        if(i<s1.length() && j<s2.length() && dp[i][j][k]!=-1)
        {
            return dp[i][j][k];
        }
        
       
        
        
        
        if(i<s1.length() && s1.at(i)==s3.at(k))
        {
            if(checkpossible(s1,s2,s3,i+1,j,k+1,dp)==true)
            {
                return true;
            }
        }
      
         
        if(j<s2.length() && s2.at(j)==s3.at(k))
        {
            if(checkpossible(s1,s2,s3,i,j+1,k+1,dp)==true)
            {
                return true;
            }
        }
        
         if(i<s1.length() && j<s2.length() && k<s3.length())
        {
             dp[i][j][k]=false;
        }
        return false;
        
     }
    
    
    
    
    bool isInterleave(string s1, string s2, string s3) {
        
        int i=0;
        int j=0;
        int k=0;
        
       vector<vector<vector<int>>> dp(s1.length()+1,vector<vector<int>>(s2.length()+1,vector<int>(s3.length()+1,-1)));
        
        if(s1.length()+s2.length()!=s3.length())
        {
            return false;
        }
        
        if(s1=="" && s2=="" && s3=="")
        {
            return true;
        }
        
        
      return checkpossible(s1,s2,s3,i,j,k,dp);
        
    }
};
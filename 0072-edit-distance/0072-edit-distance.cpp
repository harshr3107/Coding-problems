class Solution {
public:
    
    
    
    int getminimum(string word1,string word2,int ind1,int ind2,vector<vector<int>>& dp)
    {
        
        
        if(ind1==word1.length() && ind2==word2.length())
        {
            return 0;
        }
        
        if (ind1 == word1.length()) {
            return word2.length() - ind2;
        }
        if (ind2 == word2.length()) {
            return word1.length() - ind1;
        }
        
        if(dp[ind1][ind2]!=-1)
        {
            return dp[ind1][ind2];
        }
       
        
        
        int insert = 1e9+7;
        int deletee = 1e9+7;
        int replace = 1e9+7;
        int no_opp = 1e9+7;
        
        
      
        
      if(word1.at(ind1)==word2.at(ind2))
      {
          no_opp = getminimum(word1,word2,ind1+1,ind2+1,dp);
          dp[ind1][ind2]=no_opp;
          
          return dp[ind1][ind2];
          
      }else{
          
      
        
        
        
        
        //insert a character
       
         insert = 1+getminimum(word1,word2,ind1,ind2+1,dp);
        
        //delete a character
        
         deletee = 1+getminimum(word1,word2,ind1+1,ind2,dp);
        
        //repalce a character
        
        
         replace = 1+getminimum(word1,word2,ind1+1,ind2+1,dp);
        
      
      }
        
        
        dp[ind1][ind2]=min(min(insert,no_opp),min(deletee,replace));
        
        return dp[ind1][ind2];
        
        
        
        
        
    }
        
    
    
    
    
    
    
    
    int minDistance(string word1, string word2) {
        
        int ind1=0;
        int ind2=0;
        
        vector<vector<int>> dp(word1.length()+1,vector<int>(word2.length()+1,-1));
         
        return getminimum(word1,word2,ind1,ind2,dp);
        
    }
};
class Solution {
public:
    
    
    
    
    double getways(string s,string t,int i,int j,vector<vector<double>>& dp)
    {
        
        if(j==t.length())
        {
            return 1;
        }
        
        
        if(i>=s.length())
        {
            return 0;
        }
        
    
       
         if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
       
         
       
        double take = 0;
        double nottake=0;
        
        if(s.at(i)==t.at(j))
        {
            
            take = getways(s,t,i+1,j+1,dp); 
        }
        
        nottake = getways(s,t,i+1,j,dp);
        
        dp[i][j]=take+nottake;
        
        return take+nottake;
        
    }
    
    
    
    int numDistinct(string s, string t) {
    
        /*int i=0;
        int j=0;
        
        vector<vector<double>> dp(s.length(),vector<double>(t.length(),-1));
        string str="";
        
        return getways(s,t,i,j,dp);
        */
        
        vector<vector<double>> dp(s.length()+1,vector<double>(t.length()+1,0));
        
        
        for(int i=0;i<=s.length();i++)
        {
            dp[i][0]=1;
        }
        
        for(int i=1;i<=s.length();i++)
        {
            for(int j=1;j<=t.length();j++)
            {
                
                
                
                double take =0;
                double nottake=0;
                
                if(s.at(i-1)==t.at(j-1))
                {
                    take = dp[i-1][j-1];
                }
                
                nottake = dp[i-1][j];
                
                dp[i][j]=take+nottake;
                //cout<<"val of max is "<<(take+nottake)<<endl;
                
            } 
        }
        
        
        return dp[s.length()][t.length()];
        
        
        
        
        
        
    }
};
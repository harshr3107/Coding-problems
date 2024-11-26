class Solution {
public:
    
    
    int getminways(string w1,string w2,int i,int j,vector<vector<int>>& dp)
    {
        
        
        
        
        if(j>=w2.length())
        {
            
            
            return (w1.length()-i);
        }
        
        if(i>=w1.length())
        {
            return (w2.length()-j);
        }
        
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        
        int bway=INT_MAX;
        
        if(w1.at(i)==w2.at(j))
        {
            bway=getminways(w1,w2,i+1,j+1,dp);
        }
        int iway = 1+getminways(w1,w2,i,j+1,dp);
        int rway = 1+getminways(w1,w2,i+1,j+1,dp);
        int dway = 1+getminways(w1,w2,i+1,j,dp);
        
        dp[i][j] = min(min(bway,iway),min(rway,dway));
        
        return dp[i][j];
        
        
    }
    
    
    
    
    int minDistance(string w1, string w2) {
        
         vector<vector<int>>  dp(w1.length()+1,vector<int>(w2.length()+1,-1));
        
        if(w1.length()==0)
        {
            return w2.length();
        }   
        
        
            
        
        return getminways(w1,w2,0,0,dp);
        
       /* vector<vector<int>>  dp(w1.length()+1,vector<int>(w2.length()+1,0));
        
        
        for(int i=1;i<=w1.size();i++)
        {
            for(int j=1;j<=w2.size();j++)
            {
                
                if(w1.at(i-1)==w2.at(j-1))
                {
                    dp[i][j]=1+dp[i-1][j-1];
                    continue;
                }
                
                
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                
            }
            
        }
        
        cout<<dp[w1.size()][w2.size()]<<endl;
        
        
        string s="";
        
        
       int i=w1.size();
       int j=w2.size();
        
        while(i>0 && j>0)
        {
            
            if(w1.at(i-1)==w2.at(j-1))
            {
                s.push_back(w1.at(i-1));
                i--;
                j--;
                continue;
            }
            
            if(dp[i-1][j]>dp[i][j-1])
            {
                i--;
            }else{
                
                j--;
            }
            
            
        }
            
        reverse(s.begin(),s.end());
        cout<<s<<endl;
        
        
        int ans=0;
        
        
        
    
     
        

        
        
        return 0;
        */
    }
};
class Solution {
public:
    
    int getlongest(string& t1,string& t2,int ind1,int ind2,vector<vector<int>>& dp)
    {
        if(ind1<0 || ind2<0)
        {
            return 0;
        }
        
        
        if(dp[ind1][ind2]!=-1)
        {
            return dp[ind1][ind2];
        }
        
        
        if(t1.at(ind1)==t2.at(ind2))
        {
            return 1+getlongest(t1,t2,ind1-1,ind2-1,dp);
        }
        
        
        int f=0;
        
        if(ind1-1>=0)
        {
         f = getlongest(t1,t2,ind1-1,ind2,dp);
        }
        
        int s=0;
        
        if(ind2-1>=0)
        {
          s = getlongest(t1,t2,ind1,ind2-1,dp);
        }
        
        
        dp[ind1][ind2]=max(f,s);
        
        return dp[ind1][ind2];
        
        
    }
    
    
    
    
    
    
    int longestCommonSubsequence(string t1, string t2) {
        
        int ind1=t1.size()-1;
        int ind2 = t2.size()-1;
        
        vector<vector<int>> dp(ind1+1,vector<int>(ind2+1,-1));
        
        return getlongest(t1,t2,ind1,ind2,dp);
        
        
    }
};
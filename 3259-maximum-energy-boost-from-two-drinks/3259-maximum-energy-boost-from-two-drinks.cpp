class Solution {
public:
    
    
    
    
    /*long long getmax(vector<int>& a,vector<int>& b,int ai,int bi,vector<vector<long long>>& dp)
    {
        
       
       
        if(ai>=a.size() && bi>=b.size())
        {
            return 0;
        }
        
        
        
        if(ai<a.size() && bi<b.size() && dp[ai][bi]!=-1)
        {
            return dp[ai][bi];
        
        }
        
        long long takea=0;
        long long takeb=0;
        if(ai<a.size())
        {
           
        takea = a[ai]+getmax(a,b,ai+1,ai+2,dp);
        }
        
        if(bi<b.size())
        {
            //ai=bi+2;
            takeb = b[bi]+getmax(a,b,bi+2,bi+1,dp);
        }
        //cout<<"value of takea and take b is "<<takea<<" "<<takeb<<endl;
        
        if(ai<a.size() && bi<b.size())
        {
          dp[ai][bi]=max(takea,takeb);
        }
        
        return max(takea,takeb);
        
        
        
        
    }*/
    
    
    long long getmax(vector<int>& a,vector<int>& b,int cind,int k,vector<vector<long long>>& dp)
    {
        
        if(cind==a.size())
        {
            return 0;
        }
        
        if(dp[cind][k]!=-1)
        {
            return dp[cind][k];
        }
        
        long long take=0;
        long long nottake=0;
        
        if(k==1)
        {
            take = a[cind]+getmax(a,b,cind+1,1,dp);
            nottake = getmax(a,b,cind+1,0,dp);
            
        }else{
            
            take = b[cind]+getmax(a,b,cind+1,0,dp);
            nottake = getmax(a,b,cind+1,1,dp);
            
        }
        
        dp[cind][k] = max(take,nottake);
        
        return dp[cind][k];
        
        
    }
    
    
    
    long long maxEnergyBoost(vector<int>& A, vector<int>& B) {
    
        
        vector<vector<long long>> dp(A.size()+1,vector<long long>(3,-1));
        
        
        return max(getmax(A,B,0,1,dp),getmax(A,B,0,2,dp));
        
        
    }
};


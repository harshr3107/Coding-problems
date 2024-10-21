class Solution {
public:
    
    
    int getallpath(vector<vector<int>>& og,int i,int j,int m,int n,vector<vector<int>>& dp)
    {
       // cout<<"i m here for "<<i<<" "<<j<<endl;
        
        
        if(i==m && j==n)
        {
            return 1;
        }
        
        if(og[i][j]==1)
        {
            return 0;
        }
        
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        
        
        
        
        int p1=0;
        int p2=0;
        
        
        if((i+1)<=m)
        {
            //cout<<"mai yaha aaya\n";
          p1 = getallpath(og,i+1,j,m,n,dp);
        }
        
        if((j+1)<=n)
        {
           
            p2 = getallpath(og,i,j+1,m,n,dp);
            
        }
        
        dp[i][j]=p1+p2;
        return p1+p2;
        
        
        
    }
    
    
    
    
    
    
    
    
    int uniquePathsWithObstacles(vector<vector<int>>& og) {
        
        int i=0;
        int j=0;
        int m=og.size()-1;
        
        
        int n = og[0].size()-1;
        
        if(og[m][n]==1 || og[0][0]==1)
        {
            return 0;
        }
        
        
        vector<vector<int>> dp;
        
        for(int i=0;i<og.size();i++)
        {
            vector<int> v(og[i].size(),-1);
            dp.push_back(v);
        }
        
        return getallpath(og,i,j,m,n,dp);
        
        
    }
};
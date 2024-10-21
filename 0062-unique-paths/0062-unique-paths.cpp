class Solution {
public:
    
    int getallpath(int i,int j,int m,int n,vector<vector<int>>& dp)
    {
        //cout<<"i am here at "<<i<<j<<endl;
        
        
        if(i==m-1 && j==n-1)
        {
            return 1;
        }
        
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        
        
        int p1=0;
        int p2=0;
        
        if(i+1<m)
        {
          p1 = getallpath(i+1,j,m,n,dp);
        }
        if(j+1<n)
        {
            p2 = getallpath(i,j+1,m,n,dp);
        }
        
        dp[i][j]=p1+p2;
        return p1+p2;
        
        
    }
    
    
    
    
    
    int uniquePaths(int m, int n) {
        
        int i=0;
        int j=0;
        
        vector<vector<int>> dp;
        
        for(int i=0;i<m;i++)
        {
            vector<int> v(n,-1);
            dp.push_back(v);
        }
        
        return getallpath(i,j,m,n,dp);
        
    }
};
class Solution {
public:
    
    
    int getsum(vector<vector<int>>& grid,int i,int j,int m,int n,vector<vector<int>>& dp)
    {
        
        if(i==m-1 && j==n-1)
        {
            return grid[i][j];
        }
        
        
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        
        
        int left=INT_MAX;
        int right = INT_MAX;
        
        if((i+1)<m)
        {
            left=grid[i][j]+getsum(grid,i+1,j,m,n,dp);
        }
        
        if((j+1)<n)
        {
            right=grid[i][j]+getsum(grid,i,j+1,m,n,dp);
        }
        
        dp[i][j]=min(left,right);
        return min(left,right);
        
        
        
    }
    
    
    
    
    
    
    
    
    int minPathSum(vector<vector<int>>& grid) {
        
        int i=0;
        int j=0;
        int m=grid.size();
        int n=grid[0].size();
        
        vector<vector<int>> dp;
        
        for(int i=0;i<m;i++)
        {
            vector<int> v(n,-1);
            dp.push_back(v);
        }
        
        
        
        return getsum(grid,i,j,m,n,dp);
        
    }
};
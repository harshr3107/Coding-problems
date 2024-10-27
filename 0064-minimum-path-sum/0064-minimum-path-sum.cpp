class Solution {
public:
    
    
    //MEMONIZATION
    /*
    int getmini(vector<vector<int>>& grid,int i,int j,vector<vector<int>>& dp)
    {
       
        
        if(i==grid.size()-1 && j==grid[i].size()-1)
        {
            return grid[i][j];
        }
        
        
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        
        
        int right = INT_MAX;
        int down = INT_MAX;
       
        
        //he can move right
        
        if((j+1)<grid[i].size())
        {
            right=grid[i][j]+getmini(grid,i,j+1,dp);
        }
        
        //he can move down
        
        if((i+1)<grid.size())
        {
            down = grid[i][j]+getmini(grid,i+1,j,dp);
        }
       
        dp[i][j]=min(right,down);
  
        return dp[i][j];
        
    }*/
    
    
    //TABULATION
    
    int getmini(vector<vector<int>>& grid)
    {
        
        vector<vector<int>> dp(grid.size(),vector<int>(grid[0].size(),0));
        
        
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[i].size();j++)
            {
                
                if(i==0 && j==0)
                {
                    dp[i][j]=grid[i][j];
                }else{
                
                int right = grid[i][j];
                int down = grid[i][j];
                
                if((i-1)>=0)
                {
                    right+=dp[i-1][j];
                }else{
                    right+=1e9+7;
                }
                    
                    if((j-1)>=0)
                    {
                        down+=dp[i][j-1];
                    }else{
                        down+=1e9+7;
                    }
                
                    
                    dp[i][j]=min(right,down);
                
                    
                    }
                
            }
            
        }
        
        
        return dp[grid.size()-1][grid[0].size()-1];
        
    }
    
    
    
    
    
    
    int minPathSum(vector<vector<int>>& grid) {
        
        
       // vector<vector<int>> dp(grid.size(),vector<int> v(grid[0].size(),-1));
       vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), -1));

        return getmini(grid);
        
        //return getmini(grid,0,0,dp);
      
        
    }
};
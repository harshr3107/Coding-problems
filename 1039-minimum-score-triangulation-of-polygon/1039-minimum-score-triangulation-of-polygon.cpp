class Solution {
public:
    
    
    int getmin(vector<int>& values,int i,int j,vector<vector<int>>& dp)
    {
        
        
        if((i+1)==j)
        {
            return 0;
        }
        
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        
        
        int area = INT_MAX;
        
        for(int k=i+1;k<j;k++)
        {
          int area2 = values[i]*values[j]*values[k]+getmin(values,i,k,dp)+getmin(values,k,j,dp);
          area = min(area,area2);
          
            
        }
        
        dp[i][j]=area;
        
        return area;
        
    }
    
    
    
    
    
    
    
    
    int minScoreTriangulation(vector<int>& values) {
        
        int i=0;
        int j=values.size()-1;
        
        vector<vector<int>> dp(values.size(),vector<int>(values.size(),-1));
        
        return getmin(values,i,j,dp);
        
        
    }
};
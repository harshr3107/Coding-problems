class Solution {
public:
    
    
    
    int getminimumpath(vector<vector<int>>& triangle,int i,int j,vector<vector<int>>& dp)
    {
        if(i>=triangle.size() || j>=triangle[i].size())
        {
            return 0;
        }
        
      //  cout<<"the i and j are "<<i<<" "<<j<<endl;
        
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        
        
        
        int path1 = triangle[i][j]+getminimumpath(triangle,i+1,j,dp);
        int path2 = triangle[i][j]+getminimumpath(triangle,i+1,j+1,dp);
        
        dp[i][j]=min(path1,path2);
        return min(path1,path2);
        
        
    }
    
    
    int minimumTotal(vector<vector<int>>& triangle) {
        
        
        int i=0;
        int j=0;
        
        vector<vector<int>> dp;
        
        for(int i=0;i<triangle.size();i++)
        {
            vector<int> v(triangle[i].size(),-1);
            dp.push_back(v);
        }
        
        return getminimumpath(triangle,i,j,dp);
        
    }
};
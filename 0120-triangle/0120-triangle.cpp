class Solution {
public:
    
    
    
    //MEMONIZATION
    /*int getmini(vector<vector<int>>& triangle,int i,int j,vector<vector<int>>& dp)
    {
        
        
        if(i>=triangle.size() || j>=triangle[i].size())
        {
            return 0;
        }
        
        //cout<<i<<" "<<j<<endl;
        
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        
        int down = triangle[i][j]+getmini(triangle,i+1,j,dp);
        int down2 = triangle[i][j]+getmini(triangle,i+1,j+1,dp);
        
        dp[i][j]=min(down,down2);
        
        return dp[i][j];
        
        
        
        
    }*/
    
    
    //TABULATION
    
    int getmini(vector<vector<int>>& triangle)
    {
        vector<vector<int>> dp(triangle.size(),vector<int>(triangle[triangle.size()-1].size(),0));
        
        for(int i=0;i<triangle.size();i++)
        {
            for(int j=0;j<triangle[i].size();j++)
            {
                if(i==0 && j==0)
                {
                    dp[i][j]=triangle[i][j];
                }else{
                    
                    int down1 = triangle[i][j];
                    int down2 = triangle[i][j];
                    
                    if((i-1)>=0 && j<triangle[i-1].size())
                    {
                        
                        down1+=dp[i-1][j];
                    }else{
                        down1+=1e9+7;
                    }
                    
                    if((i-1)>=0 && (j-1)>=0)
                    {
                        down2+=dp[i-1][j-1];
                    }else{
                        down2+=1e9+7;
                    }
                    
                    //cout<<i<<" "<<j<<" "<<down1<<" "<<down2<<endl;
                    dp[i][j]=min(down1,down2);
                    
                }
                
            }
            
        }
        
        //cout<<triangle.size()-1<<" "<<triangle[triangle.size()-1].size()-1<<endl;
        
        int a = *min_element(dp[triangle.size()-1].begin(),dp[triangle.size()-1].end());
        
        return a;
        
    }
    
    
    
    
    int minimumTotal(vector<vector<int>>& triangle) {
        
        //vector<vector<int>> dp(triangle.size(),vector<int>(triangle[triangle.size()-1].size(),-1));
        
        //return getmini(triangle,0,0,dp);
        
        
        return getmini(triangle);
        
    }
};
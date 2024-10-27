class Solution {
public:
    
  /*  
    //MEMONOZATION
    int getmin(vector<vector<int>>& matrix,int i,int j,vector<vector<int>>& dp)
    {
        //cout<<"i am here for "<<i<<" "<<j<<endl;
        
        if(i==matrix.size()-1)
        {
            return matrix[i][j];
        }
        
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        
        int leftd=1e9+7;
        int rightd=1e9+7;
        int downd=1e9+7;
        
        if((i+1)<matrix.size())
        {
            
           if((j-1)>=0)
           {
              leftd=matrix[i][j]+getmin(matrix,i+1,j-1,dp);
           }
            
            if((j+1)<matrix[i+1].size())
            {
                rightd=matrix[i][j]+getmin(matrix,i+1,j+1,dp);
                
            }
            
            downd=matrix[i][j]+getmin(matrix,i+1,j,dp);
            
        }
        
        dp[i][j]= min(leftd,min(rightd,downd));
        
        return dp[i][j];
        
        
        
    }
    */
    
    //TABULATIOM
    
    int getmini(vector<vector<int>>& matrix)
    {
        
        vector<vector<int>> dp(matrix.size(),vector<int>(matrix[0].size(),0));
        
        
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[i].size();j++)
            {
                
                if(i==0)
                {
                    dp[i][j]=matrix[i][j];
                }else{
                    
                    
                    int downd=matrix[i][j];
                    int leftd = matrix[i][j];
                    int rightd = matrix[i][j];
                    
                    if((j-1)>=0)
                    {
                        leftd+=dp[i-1][j-1];
                    }else{
                        leftd+=1e9+7;
                    }
                    
                    if((j+1)<matrix[i-1].size())
                    {
                        rightd+=dp[i-1][j+1];
                    }else{
                        rightd+=1e9+7;
                    }
                    
                    downd+=dp[i-1][j];
                    
                    dp[i][j]=min(leftd,min(rightd,downd));
                    
                    
                    
                    
                    
                }
                
                
            }
            
        }
        
       // cout<<dp[2][0]<<" "<<dp[2][1]<<" "<<dp[2][2]<<endl;
        
        int m = matrix.size()-1;
        
        return *min_element(dp[m].begin(),dp[m].end());
        
        
    }
    
    
    
    
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        
        int mini = INT_MAX;
        
        vector<vector<int>> dp(matrix.size(),vector<int>(matrix[0].size(),-1));
        
       /* for(int j=0;j<matrix[0].size();j++)
        {
            int h = getmini(matrix,0,j,dp);
            //cout<<"val of h is "<<h<<endl;
            mini = min(mini,h);
            
        }*/
        
        return getmini(matrix);
        
        
       // return mini;
        
    }
};
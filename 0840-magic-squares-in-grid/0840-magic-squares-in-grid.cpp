class Solution {
public:
    
    bool checkbox(vector<vector<int>> grid,int rstart,int rend,int cstart,int cend)
    {
        vector<int> count(10);
        int sum1=grid[rstart][cstart]+grid[rend][cend]+grid[rstart+1][cstart+1];
        int sum2=grid[rstart][cend]+grid[rend][cstart]+grid[rstart+1][cstart+1];
        int sum3=0;
        int sum4=0;
        
        cout<<"value of sum1 is "<<sum1<<" "<<sum2<<endl;
        
        if(sum1!=sum2)
        {
            return false;
        }
        
        
        for(int i=rstart;i<=rend;i++)
        {
            sum3=0;
            for(int j=cstart;j<=cend;j++)
            {
                sum3=sum3+grid[i][j];
               
                
                if(grid[i][j]>=1 && grid[i][j]<=9)
                {
                    count[grid[i][j]]++;
                    
                }else{
                    //cout<<"mai yaha aaya kya\n";
                    return false;
                }
                
            }
            
            if(sum3!=sum1)
            {
                return false;
            }
        }
        
        
   
            
       for(int i=cstart;i<=cend;i++)
       {
           sum4=0;
           for(int j=rstart;j<=rend;j++)
           {
               sum4+=grid[j][i];
           }
          
           
           if(sum4!=sum1)
           {
               return false;
           }
           
       }
        
        
        
        for(int i=1;i<=9;i++)
        {
            if(count[i]!=1)
            {
                cout<<"i entered here for i "<<i<<endl;
                
                return false;
            }
        }
        
        return true;
        
        
        
    }
    
    
    
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        
       int n = grid.size();
       int m = grid[0].size();
        
        int rstart=0;
        int rend=2;
        int cstart=0;
        int cend=2;
        
        int ans=0;
        
        while(rend<n && cend<m)
        {
            //cout<<"i came here\n";
            
            if(checkbox(grid,rstart,rend,cstart,cend))
            {
                ans++;
            }
            
            cstart++;
            cend++;
            //cout<<"value of cend is "<<cend<<" "<<m<<endl;
            
            if(cend==m)
            {
                //cout<<"entered here\n";
                cstart=0;
                cend=2;
                rstart++;
                rend++;
                
            }
            
           
            
            
        }
        
        
        
        return ans;
        
    }
};
class neighborSum {
public:
    
   
    vector<vector<int>> nums;
    
    neighborSum(vector<vector<int>>& grid) {
        
        nums=grid;
        
    }
    
    int adjacentSum(int value) {
        
        int i;
        int j;
        
        for(i=0;i<nums.size();i++)
        {
            for(j=0;j<nums[0].size();j++)
            {
                if(nums[i][j]==value)
                {
                   int sum=0;
        int h=j-1;
        
       // cout<<"val of i and h is "<<i<<" "<<h<<endl;
        
        if(h>=0)
        {
            sum=sum+nums[i][h];
            
        }
        
        
        h=j+1;
        
        if(h<nums[i].size())
        {
            sum+=nums[i][h];
           
        }
        
        
        h=i-1;
        
        if(h>=0)
        {
            sum+=nums[h][j];
            
        }
        
        
        h=i+1;
        
        
        if(h<nums.size())
        {
            sum+=nums[h][j];
            
            
        }
        
       return sum; 
                    
                }
            }
        }
        
      
        return -1;
        
    }
    
    int diagonalSum(int value) {
        
        int i;
        int j;
        
        for(i=0;i<nums.size();i++)
        {
            for(j=0;j<nums[0].size();j++)
            {
                if(nums[i][j]==value)
                {
                    
                    
                     int h=j-1;
                     int k=i-1;
                   int sum=0;
        
        if(h>=0 && k>=0)
        {
            sum+=nums[k][h];
            
        }
        
        k=i+1;
        h=j+1;
        
        if(k<nums.size() && h<nums[0].size())
        {
            sum+=nums[k][h];
            
        }
        
        k=i-1;
        h=j+1;
        
        if(k>=0 && h<nums[0].size())
        {
            sum+=nums[k][h];
           
        }
        
        k=i+1;
        h=j-1;
        
        if( k<nums[0].size() && h>=0)
        {
            sum+=nums[k][h];
        }
        
        return sum;
                    
                    
                    
                }
            }
        }
        
        
        return -1;
    }
};

/**
 * Your neighborSum object will be instantiated and called as such:
 * neighborSum* obj = new neighborSum(grid);
 * int param_1 = obj->adjacentSum(value);
 * int param_2 = obj->diagonalSum(value);
 */
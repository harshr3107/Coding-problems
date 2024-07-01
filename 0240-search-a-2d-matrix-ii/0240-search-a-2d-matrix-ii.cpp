class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
      /*  int lowrow=0;
        int highrow=matrix.size()-1;
        
        while(highrow>=lowrow)
        {
            if(matrix[lowrow][0]<=target && matrix[lowrow][matrix[lowrow].size()-1]>=target)
            {
                int low=0;
                int high=matrix[0].size()-1;
                int mid;
                
                while(high>=low)
                {
                    mid=low+(high-low)/2;
                    
                    if(matrix[lowrow][mid]==target)
                    {
                        return true;
                    }else if(matrix[lowrow][mid]>target)
                    {
                        high=mid-1;
                    }else{
                        low=mid+1;
                    }
                    
                    
                    
                }
                
                
                
            }
            
            lowrow++;
            
            
        }*/
  
        
    int trows = matrix.size();
    int tcolumns = matrix[0].size();
        
     int crow=0;
     int ccol=tcolumns-1;
        
        while(crow<trows && ccol>=0)
        {
            
            int element = matrix[crow][ccol];
            
            if(element==target)
            {
                return true;
            }else if(element>target)
            {
                ccol--;
                
            }else{
                crow++;
            }
            
            
        }
        
        
        
        
        
        return false;   
        
    }
};
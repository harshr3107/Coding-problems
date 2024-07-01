class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int lowrow=0;
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
            
            
        }
        
        return false;   
        
    }
};
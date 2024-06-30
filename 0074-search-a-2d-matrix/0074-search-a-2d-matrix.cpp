class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int highrow=matrix.size()-1;
        int lowrow=0;
        int midrow=0;
        
        
        while(highrow>=lowrow)
        {
            midrow=lowrow+(highrow-lowrow)/2;
            
            if(matrix[midrow][0]>target)
            {
                highrow=midrow-1;
                
            }else{
                
                lowrow=midrow+1;
                
            } 
            
            
        }
        
        cout<<"high row is "<<highrow;
        
        if(highrow==-1)
        {
            return false;
        }
        
       
        int low=0;
        int high=matrix[0].size()-1;
        int mid;
        
       while(high>=low)
        {
            mid=low+(high-low)/2;
            
            if(matrix[highrow][mid]==target)
            {
                return true;
            }else if(matrix[highrow][mid]>target)
            {
                high=mid-1;
            }else{
                
                low=mid+1;
            }
        }
        
        
        
        
        
        return false;
        
    }
};



/*if(matrix[highrow][0]>target)
            {
                highrow--;
            }else{
                
                int low = 0;
                int high=matrix[0].size()-1;
                int mid;
                
                while(high>=low)
                {
                    mid = low+(high-low)/2;
                    
                    if(matrix[highrow][mid]==target)
                    {
                        return true;
                    }else if(matrix[highrow][mid]>target)
                    {
                        high=mid-1;
                    }else{
                        low=mid+1;
                    }
                    
                }
                
                break;
                
            }*/
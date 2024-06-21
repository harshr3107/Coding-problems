class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        
        
        int low=0;
        int high=arr.size()-1;
        int mid;
        
        
        while(high>low)
        {
            mid = low+(high-low)/2;
            
            if(arr[mid]<arr[mid+1])
            {
                low=mid+1;
            }else{
                high=mid;
            }
            
        }
        
        return high;
        
        
     
        /* MY SOLUTION ON FIRST INTUTION
       int low=0;
       int high=arr.size()-1;
     
        
        
        while(high>=low)
        {
            
              int mid = low + (high-low)/2;
            
            if( mid>0 && arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1])
            {
                
                return mid;
                
            }else if(mid>0 && arr[mid]<arr[mid-1])
            {
                high=mid-1;
                
            }else{
                
                low=mid+1;
            }
            
            
            
            
            
        }
        
        
        return -1;
        
        
        */
        
        
        
        
        
    }
};
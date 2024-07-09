class Solution {
public:
    int findMin(vector<int>& arr) {
        
        int low=0;
        int high=arr.size()-1;
        int mid=0;
        
        int ans=INT_MAX;
        
        while(high>=low)
        {
            
            mid = low +(high-low)/2;
            
            
            if(arr[mid]==arr[low] && arr[mid]==arr[high])
            {
                ans = min(ans,arr[mid]);
                low++;
                high--;
                continue;
            }
            
            if(arr[low]<=arr[mid])
            {
                
                ans=min(ans,arr[low]);
                low=mid+1;
                
                
                
            }else{
                
                
                ans=min(ans,arr[mid]);
                high=mid-1;
                
            }
            
        }
        
        
     
        return ans;
        
    }
};
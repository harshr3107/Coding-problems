class Solution {
public:
    
    int binarysearch(vector<int> nums,int low,int high,int target)
    {
        
          int mid;
        
        while(high>=low)
        {
            mid= low+(high-low)/2;
            
            if(nums[mid]==target)
            {
                return mid;
            }else if(nums[mid]>target)
            {
                high=mid-1;
            }else{
                low=mid+1;
            }
            
            
        }
        
        
        
     return -1;   
        
    }
    
    
    
    
    
    
    
    
    int search(vector<int>& nums, int target) {
        
        int pivot=-1;
        
        int low=0;
        int high=nums.size()-1;
        int mid=0;
        
        while(high>low)
        {
            mid = low + (high-low)/2;
            
            if(nums[mid]>=nums[0])
            {
                low=mid+1;
                
            }else{
                high=mid;
            }
            
            
         }
        
        
        pivot=low;
        
        //cout<<"pivot is at index "<<pivot<<endl;
        
        if(target==nums[pivot])
        {
            return pivot;
        }
        
        low=pivot+1;
        high=nums.size()-1;
        
        int ans=-1;
        ans = binarysearch(nums,low,high,target);
        
        if(ans!=-1)
        {
            //cout<<"i entered here\n";
            return ans;
            
        }
        
        
        low=0;
        high=pivot-1;
       // cout<<"the high for the series is "<<nums[high]<<endl;
        
        ans = binarysearch(nums,low,high,target);
        
        
        return ans;
    }
};
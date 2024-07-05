class Solution {
public:
    bool search(vector<int>& nums, int target) {
        
        
        int low=0;
        int high=nums.size()-1;
        int mid=0;
        
        
        while(high>=low)
        {
            mid = low+(high-low)/2;
            
            if(nums[mid]==target)
            {
                return true;
            }
            if(nums[mid]==nums[high] && nums[mid]==nums[low])
            {
                low++;
                high--;
                continue;
            }
            
            if(nums[low]<=nums[mid])
            {
                
                if(nums[low]<=target && nums[mid]>=target)
                {
                    high=mid-1;
                }else{
                    low=mid+1;
                }
                
                
                
            }else{   
            
           
                
                if(nums[mid]<=target && nums[high]>=target)
                {
                    low=mid+1;
                }else{
                    high=mid-1;
                }
                
                
            
                
       }
            
        }
            
            
        return false;
        
        
        
        
        
        
        
       /* int low=0;
        int high=nums.size();
        int mid;
        int pivot;
        
        cout<<"size of the array is "<<nums.size()<<endl;
        
        while(high>low)
        {
            
            
            mid=low+(high-low)/2;
            
            while(mid<nums.size() && nums[mid]==nums[mid+1])
            {
                mid++;
            }
            

            
           cout<<"current value of mid is "<<mid<<endl;
            
            if(nums[0]<=nums[mid])
            {
                low=mid+1;
            }else{
                high=mid;
            }
        }
        
        pivot=low;
        
        cout<<"pivot element is "<<low<<endl;
        
        low = 0;
        high = pivot;
        
        while(high>=low)
        {
            mid= low + (high-low)/2;
            
            if(nums[mid]==target)
            {
                return true;
            }else if(nums[mid]>target)
            {
                high=mid-1;
            }else{
                low=mid+1;
            }
                
            
            
        }
        
        
        low = pivot+1;
        high = nums.size()-1;
        
        while(high>=low)
        {
            mid= low + (high-low)/2;
            
            if(nums[mid]==target)
            {
                return true;
            }else if(nums[mid]>target)
            {
                high=mid-1;
            }else{
                low=mid+1;
            }
                
            
            
        }
        
        
        
        
        return false;
        
        */
        
        
      /*  int i=0;
        while(i<nums.size()-1 && nums[i+1]>=nums[i])
        {
            i++;
        }
        
        
        int low=0;
        int high=i;
        int mid=0;
        
         while(high>=low)
        {
            mid= low + (high-low)/2;
            
            if(nums[mid]==target)
            {
                return true;
            }else if(nums[mid]>target)
            {
                high=mid-1;
            }else{
                low=mid+1;
            }
                
        }
        
        
        low=i+1;
        high=nums.size()-1;
        mid=0;
        
         while(high>=low)
        {
            mid= low + (high-low)/2;
            
            if(nums[mid]==target)
            {
                return true;
            }else if(nums[mid]>target)
            {
                high=mid-1;
            }else{
                low=mid+1;
            }
                
        }
        
        return false;
        */
        
        
        
        
        
        
        
        
        
    }
};
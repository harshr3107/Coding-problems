class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = (left + right) / 2;
            if (mid % 2 == 1) {
                mid--;
            }
            if (nums[mid] != nums[mid + 1]) {
                right = mid;
            } else {
                left = mid + 2;
            }
        }
        return nums[left];
     
       /* int low=0;
        int high=nums.size()-1;
        int mid=0;
        
        
        if( nums.size()==1)
        {
            return nums[0];
        }
        
        while(high>=low)
        {
            mid = low+(high-low)/2;
            
            if((mid&1))
            {
                //odd number
                if(nums[mid]!=nums[mid-1])
                {
                    if(mid<nums.size()-1 && nums[mid]!=nums[mid+1])
                    {
                        return nums[mid];
                    }
                    
                    high=mid-1;
                }else{
                    low=mid+1;
                }
                
            }else{
                
                //even number
                if(mid<nums.size()-1 && nums[mid]!=nums[mid+1])
                {
                    if(mid>0 && nums[mid]!=nums[mid-1])
                    {
                        return nums[mid];
                    }
                    high=mid-1;
                    
                }else{
                    
                    low=mid+1;
                    
                }
                
                
            }
            
        }
        
        
        return nums[mid];
        */
        
        
        
        
    }
};
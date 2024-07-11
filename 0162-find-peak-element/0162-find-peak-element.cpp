class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        
        if(nums.size()==1)
        {
            return 0;
        }
        
        
        if(nums[0]>nums[1])
        {
            return 0;
        }
        
        if(nums[nums.size()-2]<nums[nums.size()-1])
        {
            return nums.size()-1;
        }
        
        
        int low=1;
        int high=nums.size()-2;
         int mid=0;
        
        while(high>=low)
        {
            mid = low+(high-low)/2;
            //cout<<"element at the mid is "<<nums[mid]<<endl;
            
            if(nums[mid-1]<nums[mid] && nums[mid]>nums[mid+1])
            {
                return mid;
                
            }else if(nums[mid]>nums[mid-1])
            {
                low=mid+1;
            }else if(nums[mid]>nums[mid+1])
            {
                high=mid-1;
            }else{
                
                high=mid-1;
            }
            
       }
        
        
        
        return -1;
        
        
        
        
        
        
    }
};
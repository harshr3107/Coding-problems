class Solution {
public:
    int findMin(vector<int>& nums) {
        
        
        int low=0;
        int high=nums.size()-1;
        int mid=0;
            
            while(high>low)
            {
                
                mid = low+(high-low)/2;
                
                if(nums[0]<=nums[mid])
                {
                    low=mid+1;
                }else{
                    high=mid;
                }
                
            }
        
        
        cout<<"pivot elment is "<<low<<endl;
        
        if(low==nums.size()-1 && nums[0]<nums[nums.size()-1])
        {
            return nums[0];
        }else{
            return nums[low];
        }
        
        
        
        
        return nums[low];
        
        
    }
};
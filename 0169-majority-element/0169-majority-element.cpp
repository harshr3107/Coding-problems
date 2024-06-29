class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        
        
        
        sort(nums.begin(),nums.end());
        
        int n = nums.size();
        
        if(n==1)
        {
            return nums[0];
        }
        
        int a= (n/2);
        
        if(nums[a]==nums[a-1])
        {
            return nums[a-1];
        }
        
            return nums[a+1];
        
        
    
      
        
        
        
        
        
        
        
        
    }
};
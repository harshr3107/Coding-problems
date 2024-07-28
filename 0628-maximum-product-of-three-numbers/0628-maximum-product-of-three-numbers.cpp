class Solution {
public:
    
    int maximumProduct(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        
        int h=nums.size();
       double a = nums[0]*nums[1]*nums[h-1];
       double b = nums[h-1]*nums[h-2]*nums[h-3];
        
        
        return max(a,b);
    
        
    }
    
};
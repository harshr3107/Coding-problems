class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        
        int h=nums.size();
        
        return (nums[h-1]-1)*(nums[h-2]-1);
        
        
    }
};
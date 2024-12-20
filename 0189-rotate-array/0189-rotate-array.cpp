class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        
        int n = nums.size();
        
        k = k%n;
        
        vector<int> ans(nums.size());
        
        for(int i=0;i<nums.size();i++)
        {
              int h = (i+k)%n;
            
             ans[h]=nums[i];
        }
        
        
       nums=ans;
        
        
    }
};
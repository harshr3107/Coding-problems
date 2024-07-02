class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        
        int start=0;
        int end=0;
        int product = nums[0];
        int ans=0;
        
        while(start<nums.size())
        {
            if(product<k && end!=nums.size()) 
            {
                ans++;
                end++;
                if(end!=nums.size())
                {
                product=product*nums[end];
                }
                
                
            }else{
                
               product=product/nums[start];
               start++;
                if(start!=nums.size())
                {
                    end=start;
                    product=nums[start];
                }
                
            }
            
        }
        
        
        return ans;
        
    }
};
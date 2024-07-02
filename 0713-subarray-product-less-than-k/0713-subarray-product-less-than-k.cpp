class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        
        int start=0;
        int end=0;
        int product = 1;
        int ans=0;
        
       /* while(start<nums.size())
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
            
        }*/
        
        if(k<=1)
        {
            return 0;
        }
        
        while(end<nums.size())
        {
            product=product*nums[end];
            while(product>=k)
            {
                product/=nums[start];
                start++;
            }
            
            ans+=(end-start+1);
            end++;
            
        }
        
        
        return ans;
        
    }
};
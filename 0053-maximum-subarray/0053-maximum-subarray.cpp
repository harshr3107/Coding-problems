class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int i=0;
        int sum=0;
        
        
        int ans=INT_MIN;
        
        while(i<nums.size())
        {
           sum=sum+nums[i];
            
            
            if(ans<sum)
            {
                ans=sum;
            }
            
            
            if(sum<0)
            {
                sum=0;
                
                
            }
            
            
           
            i++;
            
        }
        
        
        return ans;
        
        
        
    }
};




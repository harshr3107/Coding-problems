class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        double prefix=1;
        double postfix=1;
        double ans = INT_MIN;
        
        for(int i=0;i<nums.size();i++)
        {
            prefix*=nums[i];
            postfix*=nums[nums.size()-i-1];
            
            ans=max(ans,max(postfix,prefix));   
            
            if(prefix==0)
            {
                prefix=1;
            }
            
            if(postfix==0)
            {
                postfix=1;
            }
            
        }
        
        return ans;
    }
};
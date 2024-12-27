class Solution {
public:
    
    
    int minjump(vector<int>& nums,int ind,vector<int>& dp)
    {
        
        if(ind==nums.size()-1)
        {
            return 0;
        }
        
        if(dp[ind]!=-1)
        {
            return dp[ind];
        }
        
        
        
        int ans=1e9+7;
        
        for(int j=1;j<=nums[ind];j++)
        {
            if((ind+j)<nums.size())
            {
                ans = min(ans,1+minjump(nums,ind+j,dp));
            }
            
        }
        
        dp[ind]=ans;
        return dp[ind];
        
    }
    
    
    
    
    
    int jump(vector<int>& nums) {
        
        vector<int> dp(nums.size(),-1);
        
        return minjump(nums,0,dp);
        
    }
};
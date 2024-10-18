class Solution {
public:
   
    
    int getmaxsum(vector<int>& nums,int cindex,vector<int>& dp)
    {
        
        if(cindex>=nums.size())
        {
           return 0;     
        }
        
        if(dp[cindex]!=-1)
        {
            return dp[cindex];
        }
        
        
        int f1 = getmaxsum(nums,cindex+2,dp)+nums[cindex];
        int f2 = getmaxsum(nums,cindex+1,dp);
        
        dp[cindex]=max(f1,f2);
        
        return max(f1,f2);
        
        
        
    }
    
    
    
    
    
    int rob(vector<int>& nums) {
        
        vector<int> dp(nums.size()+1,-1);
        int cindex=0;
        return getmaxsum(nums,cindex,dp);
        
        
        
        
        
    }
};
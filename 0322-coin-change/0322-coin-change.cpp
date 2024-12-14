class Solution {
public:
    
    
    
    int getmin(vector<int>& nums,int i,int amount,vector<vector<int>>& dp)
    {
        
        
        
        if(amount==0)
        {
            return 0;
        }
        
        if(i>=nums.size())
        {
            return 1e9+7;
        }
        
        if(dp[i][amount]!=-1)
        {
            return dp[i][amount];
        }
        
        int take=1e9+7;
        
        
        if(amount-nums[i]>=0)
        {
            take = 1+getmin(nums,i,amount-nums[i],dp);     
        }
        
       int  nottake = getmin(nums,i+1,amount,dp);
        
        dp[i][amount] = min(take,nottake);
        return dp[i][amount];
        
        
        
    }
    
    
    
    int coinChange(vector<int>& coins, int amount) {
        
        sort(coins.begin(),coins.end(),greater<int>());
        vector<vector<int>> dp(coins.size(),vector<int>(amount+1,-1));
        
        int a = getmin(coins,0,amount,dp);
        
        if(a>=1e9+7)
        {
            return -1;
        }
        
        return a;
    }
};
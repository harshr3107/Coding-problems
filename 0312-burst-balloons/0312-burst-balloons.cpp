class Solution {
public:
    
    
    int getmax(vector<int>& nums,int start,int end,vector<vector<int>>& dp)
    {
        
        if(start>end)
        {
            return 0;
        }
        
        
        if(dp[start][end]!=-1)
        {
            return dp[start][end];
        }
        
        int a = INT_MIN;
        
        for(int j=start;j<=end;j++)
        {
            int h = nums[start-1]*nums[j]*nums[end+1]+getmax(nums,start,j-1,dp)+getmax(nums,j+1,end,dp);
            a=max(a,h);
        }
        
        dp[start][end]=a;
        return a;
    }
    
    
    
    
    
    int maxCoins(vector<int>& nums) {
        
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        
        vector<vector<int>> dp(nums.size()+2,vector<int>(nums.size()+2,-1));
        
        
        return getmax(nums,1,nums.size()-2,dp);
         
        
        
    }
};
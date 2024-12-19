class Solution {
public:
    
    
    
    bool getjump(vector<int>& nums,int cindex,vector<int>& dp)
    {
        
        if(cindex>=nums.size())
        {
            return false;
        }
        
        if(dp[cindex]!=-1)
        {
            return dp[cindex];
        }
        
        
        if(cindex==nums.size()-1)
        {
            dp[cindex]=true;
            return true;
        }
        
       
        
        
        
        
        for(int i=1;i<=nums[cindex];i++)
        {
            if(getjump(nums,cindex+i,dp)==true)
            {
                dp[cindex]=true;
                return true;
            }
            
        }
        
        dp[cindex]=false;
        return false;
        
        
    }
    
    
    
    
    bool canJump(vector<int>& nums) {
       
        
        int cindex=0;
        vector<int> dp(nums.size(),-1);
        return getjump(nums,cindex,dp);
        
       
        
    }
};
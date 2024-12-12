class Solution {
public:
    
    
    int getmaxscr(vector<int>& nums,int i,int j,bool lastplay,vector<vector<int>>& dp)
    {
        
        if(i>j)
        {
            return 0;
        }
        
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        
        int ans=0;
        int left=0;
        int right=0;
        
        if(lastplay)
        {
            left = nums[i]+getmaxscr(nums,i+1,j,0,dp);
            right = nums[j]+getmaxscr(nums,i,j-1,0,dp);
            
            ans = max(left,right);
            
            
        }else{
            
            
          left =  -nums[i]+getmaxscr(nums,i+1,j,1,dp);
         right = -nums[j]+getmaxscr(nums,i,j-1,1,dp);
            
            ans = min(left,right);
            
            
        }
        
        dp[i][j]=ans;
        return ans;
        
        
    }
    
    
    
    
    
    bool predictTheWinner(vector<int>& nums) {
    
        
        int i=0;
        int j = nums.size()-1;
        bool lastplay=1;
        
        vector<vector<int>> dp(nums.size(),vector<int>(nums.size(),-1));
        
        int h = getmaxscr(nums,i,j,lastplay,dp);
        
        if(h>=0)
        {
            return true;
        }
        
        return false;
        
        
        
    }
};
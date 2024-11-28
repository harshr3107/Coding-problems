class Solution {
public:
    
    
   /* int getmaxseq(vector<int>& nums,int index,int lastind,vector<vector<int>>& dp)
    {
        
        if(index>=nums.size())
        {
            return 0;
        }
        
        if(lastind!=-1 && dp[index][lastind]!=-1)
        {
            return dp[index][lastind];
        }
        
        
        int take=0;
        
        if(lastind==-1 || nums[lastind]<nums[index])
        {
            take = 1+getmaxseq(nums,index+1,index,dp);
        }
        
        int nottake = getmaxseq(nums,index+1,lastind,dp);
        
        if(lastind!=-1)
        {
          dp[index][lastind]=max(take,nottake);
           return dp[index][lastind]; 
        }
        
        return max(take,nottake);
        
        
    }*/
    
    
    //trting to conver to 1 based indexing
    
     int getmaxseq(vector<int>& nums,int index,int lastind,vector<vector<int>>& dp)
    {
        
        if(index<0)
        {
            return 0;
        }
        
        if(dp[index][lastind]!=-1)
        {
            return dp[index][lastind];
        }
        
        
        int take=0;
        
        if(lastind==nums.size() || nums[lastind]>nums[index])
        {
            take = 1+getmaxseq(nums,index-1,index,dp);
        }
        
        int nottake = getmaxseq(nums,index-1,lastind,dp);
        
        
          dp[index][lastind]=max(take,nottake);
          return dp[index][lastind]; 
     
        
    }
    
    
    int lengthOfLIS(vector<int>& nums) {
     
       /* int index=0;
        int lastind = -1;
        int lasttaken=INT_MIN;
        vector<vector<int>> dp(nums.size()+1,vector<int>(nums.size()+1,-1));
        
        return getmaxseq(nums,index,lastind,dp);
        */
        
         int index=nums.size()-1;
        int lastind = nums.size();
        
        vector<vector<int>> dp(nums.size()+1,vector<int>(nums.size()+1,-1));
        
        return getmaxseq(nums,index,lastind,dp);
        
        
        
     
        
    }
};
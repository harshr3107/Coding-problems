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
        
        /*
         int index=nums.size()-1;
        int lastind = nums.size();
        
        vector<vector<int>> dp(nums.size()+1,vector<int>(nums.size()+1,-1));
        
        return getmaxseq(nums,index,lastind,dp);
        
        */
        
        //Tabulation

        
        int n = nums.size();
        vector<vector<int>> dp(nums.size()+1,vector<int>(nums.size()+1,0));
        int ans=INT_MIN;
        
        for(int index=n-1;index>=0;index--)
        {
            
            for(int lastind=n;lastind>=0;lastind--)
            {
                 int take=0;
        
               if(lastind==n || nums[lastind]<nums[index])
              {
                 take = 1+dp[index+1][index];
              }
        
                int nottake = dp[index+1][lastind];
        
        
          dp[index][lastind]=max(take,nottake);
                ans=max(ans,dp[index][lastind]);
            }
       
        }
        
        return ans;
    }
};

/*
int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0)); // DP table with dimensions (n+1)x(n+1)

    // Tabulation
    for (int index = 0; index < n; index++) {
        for (int lastind = 0; lastind <= n; lastind++) {
            // Choice 1: Take the current number if it forms an increasing subsequence
            int take = 0;
            if (lastind == n || nums[index] > nums[lastind]) {
                take = 1 + dp[index + 1][index];
            }

            // Choice 2: Skip the current number
            int nottake = dp[index + 1][lastind];

            // Maximize the result
            dp[index][lastind] = max(take, nottake);
        }
    }

    // The answer is stored in dp[0][n], considering no element is initially picked
    return dp[0][n];
}


*/
class Solution {
public:
    
    
 /*int getmax(vector<int>& nums,int cindex,vector<int>& dp)
 {
     if(cindex>=nums.size())
     {
         return 0;
     }
     
     if(dp[cindex]!=-1)
     {
         return dp[cindex];
     }
     
     
     int left = getmax(nums,cindex+2,dp)+nums[cindex];
     int right = getmax(nums,cindex+1,dp);
     
     
     dp[cindex]=max(left,right);
     
     return max(left,right);
     
     
     
 }*/
    
    
    int getmax(vector<int>& nums,vector<int>& dp)
   {
     
        
       dp[0]=nums[0];
        
        for(int i=1;i<nums.size();i++)
        {
            int left=nums[i];
            int right = INT_MIN;
            if(i>=2)
            {
                left = nums[i]+dp[i-2];
               
            }
            
             right = dp[i-1];
            
            dp[i] = max(left,right);
            
         
        }
        
        return dp[nums.size()-1];
        
        
     
        
        
   
     
     
     
 }
    
    
    
    
    
    int rob(vector<int>& nums) {
        
        
        if(nums.size()==1)
        {
            return nums[0];
        }
        
        
        vector<int> v1;
        vector<int> v2;
        
        //convert it into tabular form
        
        
        for(int i=0;i<nums.size();i++)
        {
            if(i==0)
            {
                v1.push_back(nums[i]);
                continue;
            }
            
            if(i==nums.size()-1)
            {
                v2.push_back(nums[i]);
                continue;
            }
            
            v1.push_back(nums[i]);
            v2.push_back(nums[i]);
        
        }
        
        vector<int> dp(nums.size(),-1);
        
        int a = getmax(v1,dp);
        
        vector<int> dp2(nums.size(),-1);
        
        int b = getmax(v2,dp2);
        
        
        
        return max(a,b);
        
        
        
        
        
    }
};
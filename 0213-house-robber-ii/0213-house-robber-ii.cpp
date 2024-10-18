class Solution {
public:
    
    
 int getmax(vector<int>& nums,int cindex,vector<int>& dp)
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
     
     
     
 }
    
    
    
    
    
    int rob(vector<int>& nums) {
        
        
        vector<int> v1;
        vector<int> v2;
        
        
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
        
        int a = getmax(v1,0,dp);
        
        vector<int> dp2(nums.size(),-1);
        
        int b = getmax(v2,0,dp2);
        
        
        
        return max(a,b);
        
        
        
        
        
    }
};
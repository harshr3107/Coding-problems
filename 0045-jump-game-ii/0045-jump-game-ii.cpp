class Solution {
public:
    
    
   long long getjump(vector<int>& nums,int cindex,vector<int>& dp)
    {
        //cout<<"the cindex is "<<cindex<<endl;
        
        if(cindex>=(nums.size()-1))
        {
            return 0;
        }
        
        
       if(dp[cindex]!=-1)
        {
            return dp[cindex];
        }
        
        long long ans=INT_MAX;
        
        for(int i=1;i<=nums[cindex];i++)
        {
            long long jump = 1+getjump(nums,cindex+i,dp);
            ans=min(ans,jump);
            
        }
            
        dp[cindex]=ans;
        
        return dp[cindex];
        
        
        
    }
    
    
    
    
    
    int jump(vector<int>& nums) {
        
        int cindex=0;
        vector<int> dp(nums.size()+1,-1);
        
        return getjump(nums,cindex,dp);
        

        
        
        
    }
};
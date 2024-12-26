class Solution {
public:
    
    
    int getnumber(vector<int>& nums,int target,int ind,map<string,int>& dp)
    {
        
        if(ind==nums.size())
        {
            if(target==0)
            {
                return 1;
            }

                return 0;
        }
        
        string s = to_string(target)+"#"+to_string(ind);
        
        if(dp.count(s))
        {
            return dp[s];
        }
        
        
        
        
        
        int plus = getnumber(nums,target+ nums[ind],ind+1,dp);
        int minus = getnumber(nums,target-nums[ind],ind+1,dp);
        
        dp[s] = plus+minus;
        
        return dp[s];
        
        
        
    }
    
    
    
    
    
    int findTargetSumWays(vector<int>& nums, int target) {
        
        map<string,int> dp;
        int ind=0;
        return getnumber(nums,target,ind,dp);
        
    }
};
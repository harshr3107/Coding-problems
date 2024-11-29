class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        
        
        vector<int> dp(nums.size(),1);
        vector<int> count(nums.size(),1);
        
        for(int i=0;i<nums.size();i++)
        {
            for(int j=0;j<i;j++)
            {
                
                
                if(nums[i]>nums[j])
                {
                    if(dp[i]==dp[j]+1)
                    {
                        count[i]+=count[j];
                    }
                    
                    if(dp[i]<dp[j]+1)
                    {
                      dp[i]=dp[j]+1;
                      count[i]=count[j];
                    }
                
                }
                
                
                
            }
            
        }
        
        
        int h = *max_element(dp.begin(),dp.end());
        int ans=0;
        
        for(int i=0;i<nums.size();i++)
        {
            //cout<<dp[i]<<" "<<count[i]<<endl;
            if(dp[i]==h)
            {
                ans+=count[i];
            }
            
        }
        
        return ans;
        
    }
    
    
};
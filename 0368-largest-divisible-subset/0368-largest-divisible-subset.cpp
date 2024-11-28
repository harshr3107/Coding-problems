class Solution {
public:
    
    
    
    
    
    
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        
     /*vector<int>  ans;
     int index=0;   
     vector<int> cur;
     int lastind=-1;
    
        
        
     getmax(nums,index,lastind,cur,ans);*/
        
        sort(nums.begin(),nums.end());
        
        vector<int> dp(nums.size(),1);
        vector<int> hash;
        
        for(int i=0;i<nums.size();i++)
        {
            hash.push_back(i);    
        }
        
        
        
        for(int i=0;i<nums.size();i++)
        {
            for(int j=0;j<i;j++)
            {
                if((nums[i]%nums[j])==0)
                {
                    if(dp[j]+1>dp[i])
                    {
                        //cout<<"i entered here\n";
                        dp[i]=dp[j]+1;
                        hash[i]=j;
                    }
                    
                }
                
                
            }
        }
        
        
        vector<int> ans;
        
        auto it = max_element(dp.begin(),dp.end());
        
        int ind = it-dp.begin();
        
        while(hash[ind]!=ind)
        {
            ans.push_back(nums[ind]);
            ind=hash[ind];
        }
          ans.push_back(nums[ind]);
        
        return ans;
        
        
        
         
        
    }
};
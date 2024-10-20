class Solution {
public:
    
    
    int findgreatest(int num,vector<int>& dp)
    {
        
          for(int j=num/2;j>=2;j--)
          {
              if((num%j)==0)
              {
                  dp[num]=j;
                  return j;
              }
          }
              
        return -1;
    }
    
    
    
    
    int minOperations(vector<int>& nums) {
        
        
        
        vector<int> dp(1000001,-1);
        
        
        int j=nums.size()-2;
        int ans=0;
        
        while(j>=0)
        {
            
            if(nums[j]>nums[j+1])
            {
                
                while(nums[j]>nums[j+1])
                {
                    int h ;
                    
                    if(dp[nums[j]]!=-1)
                    {
                        h=dp[nums[j]];
                    }else{
                        
                        h=findgreatest(nums[j],dp);
                    }
                    
                    
                 
                
                  if(h==-1)
                  {
                    return -1;
                  }
                    ans++;
                    nums[j]=nums[j]/h;
                    
                    
                }
                
                
                
            }
            
            j--;
            
        }
        
        return ans;
        
        
        
        
    }
};
class Solution {
public:
    
    int getmin(vector<int>& nums,int index,int k,int op1,int op2,vector<vector<vector<int>>>& dp)
    {
        
        if(index>=nums.size())
        {
            return 0;
        }
        
        if(dp[index][op1][op2]!=-1)
        {
            return dp[index][op1][op2];
        }
        
        int tk1=0;
        int tk2=INT_MAX;
        int tk3=INT_MAX;
        int tk4 = INT_MAX;
        
        tk1=nums[index]+getmin(nums,index+1,k,op1,op2,dp);
        
        if(op1>0)
        {
          
            float a = static_cast<float>(nums[index])/2;
            tk2 = round(a)+getmin(nums,index+1,k,op1-1,op2,dp);
          
        }
        
        if(nums[index]>=k && op2>0)
        {
           
            tk3 = (nums[index]-k)+getmin(nums,index+1,k,op1,op2-1,dp);
            
        }
        
        if(op1>0 && op2>0 && nums[index]>=k)
        {
          int u;
          int v;
            int b =nums[index]-k;
            float a = static_cast<float>(b)/2;
            u = round(a);
                
               
             a = static_cast<float>(nums[index])/2;
             v = round(a);
            
            if(v>=k)
            {
                v=v-k;
            }
                
                
            tk4 = min(u,v)+getmin(nums,index+1,k,op1-1,op2-1,dp);
            
            
            
            
            
            
            
        }
        
        
        
        
        dp[index][op1][op2] = min(min(tk1,tk2),min(tk3,tk4));
        
        return dp[index][op1][op2];
        
    }
    
    
    
    
    
    
    
    
    
    int minArraySum(vector<int>& nums, int k, int op1, int op2) {
        
        vector<vector<vector<int>>> dp(nums.size(),vector<vector<int>>(op1+2,vector<int>(op2+1,-1)));
        
        
        
        int index=0;
        
        
        
        return getmin(nums,index,k,op1,op2,dp);
        
        
        for(int i=0;i<nums.size();i++)
        {
            cout<<dp[i][0][0]<<" ";
            
        }
        
        cout<<endl;
        
      
        
    }
};
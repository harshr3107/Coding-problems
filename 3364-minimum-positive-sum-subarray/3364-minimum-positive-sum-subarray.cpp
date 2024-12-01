class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        
        vector<int> prefix(nums.size(),0);
        int sum=0;
        
        int x=l-1;
        int y=r-1;
        
        
        for(int k=0;k<nums.size();k++)
        {
          
            sum+=nums[k];
            prefix[k]=sum;
        }
        
        int ans=INT_MAX;
        
        int i=0;
        
        while((i+l-1)<nums.size())
        {
            
            //cout<<"i entrtered here for i: "<<i<<" x: "<<x<<" y: "<<y<<" ans : "<<ans<<endl;
            
            for(int k=x;k<=y;k++)
            {
                if(k>=nums.size())
                {
                    break;
                }   
                    
                
                if(i==0)
                {
                    if(prefix[k]>0)
                    {
                        ans=min(ans,prefix[k]);
                    }
                    
                }else{
                    
                    if((prefix[k]-prefix[i-1])>0)
                    {
                        ans=min(ans,prefix[k]-prefix[i-1]);
                    }
                    
                }
                
            }
            
            i++;
            x++;
            y++;
            
            
            
        }
        
        
       return ans==INT_MAX?-1:ans;
        
        
        
        
        
       
        
        
        
    }
};
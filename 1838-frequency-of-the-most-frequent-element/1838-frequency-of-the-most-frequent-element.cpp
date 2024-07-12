class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        
        
        
        
        int j;
        sort(nums.begin(),nums.end());
        int i=nums.size()-1;
        int ans=1;
        int maxi = INT_MIN;
        int count;
        int m;
        
        while(i>=ans)
        {
            //cout<<"current value of i is "<<i<<" and val is "<<nums[i]<<endl;
            
            maxi=nums[i];
            j=i-1;
            count=1;
            m=0;
            
          while(j>=0 && m<=k)
          {
               m+=(maxi-nums[j]);
               count++;
               j--;
              
          }   
          
            //cout<<"value of j here is "<<j<<endl;
            //cout<<"value of m is "<<m<<endl;
            
            if(j==-1 && m<=k)
            {
                count=count;
            }else{
                
               count--;
                
            }
            
            ans=max(ans,count);
            i--;
            
        }
            
            return ans;
    }
};
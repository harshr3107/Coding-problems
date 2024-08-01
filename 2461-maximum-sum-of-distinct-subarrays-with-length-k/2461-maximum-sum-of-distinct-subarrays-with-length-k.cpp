class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        
       
        
        //find first subarray which satisfies the given conditions
        
       
        int i=0;
        int j=0;
        long long ans=0;
        
        map<int,int> m;
        int len=0;
        long long sum=0;
        
        while(i<nums.size()-k+1)
        {
            //cout<<"current value of i "<<i<<" and j is "<<j<<endl;
            
            m[nums[j]]++;
            len++;
            sum=sum+nums[j];
            
          //cout<<"\ncurrent value of sum is "<<sum<<endl;
            
            if(m[nums[j]]==2)
            {
               // cout<<"mai yaha aaayahoon\n";
               // cout<<"value of i before "<<i<<endl;
                while(nums[i]!=nums[j])
                {
                    
                    len--;
                    m[nums[i]]--;
                    sum=sum-nums[i];
                    i++;
                }
                
                sum-=nums[i];
                m[nums[i]]--;
                len--;
                i++;
                //cout<<"value of i after "<<i<<endl;
                
                //cout<<"current value of sum-2 is "<<sum<<endl;
            }
            
            if(len==k)
            {
                
                //cout<<"current value of i-2 and j-2 is "<<i<<" "<<j<<endl;
                //cout<<"sum is "<<sum<<endl;
                ans = max(ans,sum);
                len--;
                m[nums[i]]--;
                sum-=nums[i];
                i++;
                //j--;
                
                
                
            }
                
                j++;
                
                
            
            
            
            
        }
        
        return ans;
        
        
        
    }
};
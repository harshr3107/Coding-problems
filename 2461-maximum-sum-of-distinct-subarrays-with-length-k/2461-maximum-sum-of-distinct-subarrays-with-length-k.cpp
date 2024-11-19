class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        
        
        map<int,int> mp;
        
        int i=0;
        int j=0;
        
        int a=0;
        long long ans=0;
        long long csum=0;
        int h=0;
        
        while(i<=nums.size()-k)
        {
            
            //cout<<"value of i ans j is "<<i<<" "<<j<<endl;
            
            
            while(j<nums.size() && a!=k)
            {
                if(mp.count(nums[j])==1 && mp[nums[j]]>=1)
                {
                      while(i<j && nums[i]!=nums[j])
                      {
                          csum-=nums[i];
                          mp[nums[i]]--;
                          i++;
                          a--;
                          h--;
                      }
                    
                    i++;
                   
                }else{
                    h++;
                    csum+=nums[j];
                    mp[nums[j]]++;
                    a++;
                }
                
                j++;
                
                
            }
            
            //cout<<"value of i ans j is "<<i<<" "<<j<<endl;
            //cout<<"sum is "<<csum<<endl;
            //cout<<"val of h is "<<h<<endl<<endl;
            if(h==k)
            {
                ans=max(ans,csum);
            }
            
            if(i<nums.size())
            {
              csum-=nums[i];
                mp[nums[i]]--;
            }
            a--;
            h--;
            i++;
        
                
            
            
            
            
        }
        
        
        return ans;
        
    }
};
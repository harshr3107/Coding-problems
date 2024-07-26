class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        
        map<int,int> mp;
        
        
        int low=0;
        int high=0;
        
        int ans=INT_MIN;
        
        
        while(high<nums.size() && mp[nums[high]]<k)
        {
            mp[nums[high]]++;
            high++;
            
        }
        
       ans = max(ans,high-low);
        
        cout<<"value of ans is "<<ans<<endl;
        
        
        while(high<nums.size())
        {
            if(mp[nums[high]]>=k)
            {
                
                
            while(nums[low]!=nums[high])
            {
                mp[nums[low]]--;
                low++;
            }
              
            mp[nums[low]]--;
            low++;
            mp[nums[high]]++;
            high++;
                
            }else{
                
                mp[nums[high]]++;
                high++;
                
            }
            
            ans = max(ans,high-low);
            
            
        }
        
        
        return ans;
        
        
    }
};
class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        
        int tsum=0;
        
        for(int i=0;i<nums.size();i++)
        {
            tsum = (tsum+nums[i])%p;
        }
        
        
        if(tsum==0)
        {
            return 0;
        }
        
        //cout<<"val of tsum is "<<tsum<<endl;
        
        //we want the subarray with sum%k = tsum;
        
        map<int,int> mp;
        int mini= INT_MAX;
        int csum=0;
        mp[0]=-1;
        
        
        for(int i=0;i<nums.size();i++)
        {
                  csum = (csum+nums[i])%p;
                 
                  int t = (csum-tsum+p)%p;
               
              
               
            
               if(mp.count(t))
               {
                  // cout<<"i entered here for "<<nums[i]<<" and val of t is "<<t<<endl;   
                   mini = min(mini,i-mp[t]);
                  
              }
            
            mp[csum]=i;
                   
                   
        }
        
        
       
        
        
        return (mini == INT_MAX || mini == nums.size()) ? -1 : mini;

        
        
        
        
    }
};

/*
class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int tsum = 0;
        
        // Step 1: Calculate total sum modulo p
        for (int i = 0; i < nums.size(); i++) {
            tsum = (tsum + nums[i]) % p;
        }
        
        // If the total sum is already divisible by p, no subarray needs to be removed
        if (tsum == 0) {
            return 0;
        }
        
        // Step 2: Use a map to track prefix sums modulo p
        map<int, int> mp;
        mp[0] = -1;  // Initialize to handle cases where subarray starts from index 0
        int csum = 0;
        int mini = INT_MAX;  // Track the minimum length of the subarray
        
        // Step 3: Iterate over the array and calculate prefix sums
        for (int i = 0; i < nums.size(); i++) {
            csum = (csum + nums[i]) % p;
            
            // Calculate the required modulo to remove
            int t = (csum - tsum + p) % p;
            
            // Check if there is a valid prefix sum that can form the desired subarray
            if (mp.count(t)) {
                mini = min(mini, i - mp[t]);
            }
            
            // Update the map with the current prefix sum modulo value
            mp[csum] = i;
        }
        
        // If we found a valid subarray, return its length, otherwise return -1
        return (mini == INT_MAX || mini == nums.size()) ? -1 : mini;
    }
};
*/
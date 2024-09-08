class Solution {
public:
    long long findMaximumScore(vector<int>& nums) {
        
        long long i=0;
        long long j;
        
        long long ans=0;
        
        while(i<nums.size()-1)
        {
            j=i+1;
            
            //cout<<"i entered here for i "<<i<<endl;
            
            while(j<nums.size() && nums[j]<nums[i])
            {
                j++;
            }
            
            
            
            if(j==nums.size())
            {
                 ans+=(j-i-1)*nums[i];
            }else{            
            ans = ans + ((j-i)*(nums[i]));
            }
            i=j;
            //cout<<"val of ans is "<<ans<<endl;     
            
            
            
        }
        
        
        return ans;
    
        
        
    }
};
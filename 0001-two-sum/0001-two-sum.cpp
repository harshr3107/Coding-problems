class Solution {
public:
    vector<int> twoSum(vector<int> nums, int target) {
        
        int i=0;
        int j=1;
        vector<int> v;
        int sum=0;
        int n = nums.size();
        
        
        
        
        
        while(i<n-1)
        {
            sum=nums[i]+nums[j];
            
            if(sum==target)
            {
                v.push_back(i);
                v.push_back(j);
                return v;
                
            }else{
                
                j++;
                if(j==n)
                {
                    i++;
                    j=i+1;
                }
                
            }
            
            
            
        }
        
        return v;
        
        
            
            
        
        
        
        return v;
        
        
    }
};
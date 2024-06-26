class Solution {
public:
    bool check(vector<int>& nums) {
        
        int ans=false;
        int i=0;
        int a=0;
        
        if(nums.size()==1)
        {
            return true;
        }
        
        while(i<nums.size())
        {
            
            if(nums[i]>nums[(i+1)%nums.size()])
            {
                a++;
            }
            
            if(a>1)
            {
                return false;
            }
            
            
            i++;
            
            
            
        }
        
        
        
        return true;
    }
};
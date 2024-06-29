class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int currentpos=0;
        int i=1;
        nums[currentpos]=nums[0];
        
        while(i<nums.size())
        {
            if(nums[i]!=nums[i-1])
            {
                currentpos++;
                nums[currentpos]=nums[i];
            }
                    
                    i++;
            
            
        }
                    
                    
                    return currentpos+1;
        
        
    }
};
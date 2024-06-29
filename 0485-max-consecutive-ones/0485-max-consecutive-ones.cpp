class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        
        
        int maxone = INT_MIN;
        int a=0;
        
        for(int i=0;i<nums.size();i++)
        {
            
            if(nums[i]==1)
            {
                a++;
            }else{
                
                if(maxone<a)
                {
                    maxone=a;
                }
                a=0;
                
            }
            
        }
        
        if(a>maxone)
        {
            maxone=a;
        }
        
        
        return maxone;
        
        
        
    }
};
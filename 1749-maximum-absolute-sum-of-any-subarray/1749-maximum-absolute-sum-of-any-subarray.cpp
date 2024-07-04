class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        
        
        if(nums.size()==1)
        {
            return abs(nums[0]);
        }
        
        //vector<int> prefix;
        int min=INT_MAX;
        int max=INT_MIN;
        int sum=0;
        
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            if(sum>max)
            {
                max=sum;
            }
            
            if(sum<min)
            {
                min=sum;
            }
        }
        
        if(min>=0 && max>=0)
        {
            return max;
        }
        
        if(min<=0 && max<=0)
        {
            return abs(min);
        }
        
        
        
        return abs(max-min);
        
        
    }
};
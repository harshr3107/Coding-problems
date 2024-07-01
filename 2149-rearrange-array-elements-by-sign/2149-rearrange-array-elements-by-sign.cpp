class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        
        vector<int> ans(nums.size());
        int evenpos=0;
        int oddpos=1;
        
        
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>0)
            {
                   ans[evenpos]=nums[i];
                   evenpos+=2;
            }else{
                ans[oddpos]=nums[i];
                oddpos+=2;
            }
            
            
        }
        
        
        return ans;
        
    }
};
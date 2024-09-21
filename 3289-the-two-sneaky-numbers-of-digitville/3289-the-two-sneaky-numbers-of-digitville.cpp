class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        
        set<int> s;
        vector<int> ans;
        
        for(int i=0;i<nums.size();i++)
        {
            if(s.count(nums[i]))
            {
                ans.push_back(nums[i]);
                
            }else{
                s.insert(nums[i]);
            }
            
        }
        
        
        return ans;
        
    }
};
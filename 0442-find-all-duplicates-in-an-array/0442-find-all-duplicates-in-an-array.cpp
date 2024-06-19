class Solution {
public:
    vector<int> findDuplicates(vector<int> nums) {
        
        
        vector<int> visited(nums.size()+1,0);
        vector<int> ans;
        
        
        for(int i=0;i<nums.size();i++)
        {
            visited[nums[i]]++;
            if(visited[nums[i]]>1)
            {
                ans.push_back(nums[i]);
            }
        }
        
        return ans;
        
        
        
        
       
        
        
        
        
    }
};
class Solution {
public:
    
    
    void getsubsets(vector<int> nums,int ind,vector<int> v,vector<vector<int>>& ans)
    {
        if(ind==nums.size())
        {
            return;
        }   
            
        v.push_back(nums[ind]);
        getsubsets(nums,ind+1,v,ans);
        ans.push_back(v);
        v.pop_back();
        getsubsets(nums,ind+1,v,ans);
       
        
        
    }
    
    
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int>> ans;
        vector<int> v;
        ans.push_back(v);
        
        getsubsets (nums,0,v,ans);
        
        return ans;
        
    }
};
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        vector<vector<int>> ans;
        vector<int> v;
        ans.push_back(v);
        
        getallcomb(nums,0,v,ans);
        
       sort(ans.begin(),ans.end());
        
        auto it 
        = unique(ans.begin(), ans.end()); 
 
         ans.erase(it, ans.end());
        
        return ans;
        
    }
    
    
    void getallcomb(vector<int> nums,int ind,vector<int> v,vector<vector<int>>& ans)
    {
        
        if(ind==nums.size())
        {
            sort(v.begin(),v.end());
            ans.push_back(v);
            return;
        }
        
        v.push_back(nums[ind]);
        getallcomb(nums,ind+1,v,ans);
        
        v.pop_back();
        getallcomb(nums,ind+1,v,ans);
        
        
        
        
    }
};
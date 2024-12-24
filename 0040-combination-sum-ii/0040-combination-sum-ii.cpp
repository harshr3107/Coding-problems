class Solution {
public:
    
    
    
    void getallcombi(vector<int>& nums,int target,int ind,vector<int>& v,set<vector<int>>& ans)
    {
        
        if(target==0)
        {
            
            ans.insert(v);
            return;
        }
        
        if(ind<0)
        {
            return;
        }
        
        
        
        
        if(target-nums[ind]>=0)
        {
            v.push_back(nums[ind]);
            getallcombi(nums,target-nums[ind],ind-1,v,ans);
            v.pop_back();
        }
        
        while(ind>0 && nums[ind]==nums[ind-1])
        {
            ind--;
        }
        
        getallcombi(nums,target,ind-1,v,ans);
    }
    
    
    
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        
        
      
        sort(nums.begin(),nums.end());
        set<vector<int>> ans;
        vector<int> v;
        
        getallcombi(nums,target,nums.size()-1,v,ans);
        
        
        vector<vector<int>> a(ans.begin(),ans.end());
        
        return a;
        
        
        
    }
};
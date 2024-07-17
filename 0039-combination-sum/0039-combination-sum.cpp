class Solution {
public:
    
    void getcomb(vector<int> candidates,int ind,int target,vector<int> v,vector<vector<int>>& ans)
    {
        if(ind==candidates.size() || target<0)
        {
           if(target==0)
           {
            ans.push_back(v);
            return;
           }
        
            
            
            return;
        }
        
        
        
        
        v.push_back(candidates[ind]);
        target=target-candidates[ind];
        getcomb(candidates,ind,target,v,ans);
        v.pop_back();
        target=target+candidates[ind];
        getcomb(candidates,ind+1,target,v,ans);
        
    }
    
    
    
    
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<vector<int>> ans;
        vector<int> v;
        getcomb(candidates,0,target,v,ans);
            
            
            return ans;
        
    }
};
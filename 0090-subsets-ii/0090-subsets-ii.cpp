class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        vector<vector<int>> ans;
        vector<int> v;
        
        sort(nums.begin(),nums.end());
        
        getallcomb(nums,0,v,ans);
        
      /* sort(ans.begin(),ans.end());
        
        auto it 
        = unique(ans.begin(), ans.end()); 
 
         ans.erase(it, ans.end());
        */
        return ans;
        
    }
    
    
   /* void getallcomb(vector<int> nums,int ind,vector<int> v,vector<vector<int>>& ans)
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
        
        
        
        
    }*/
    
    
    void getallcomb(vector<int> nums,int ind,vector<int> v,vector<vector<int>>& ans)
    {
        
           ans.push_back(v);
            
            
        
        
        for(int i=ind;i<nums.size();i++)
        {
            if(i>ind && nums[i]==nums[i-1])
            {
                continue;
            }
            
            v.push_back(nums[i]);
            getallcomb(nums,i+1,v,ans);
            
           
            v.pop_back();
           
            
        }
        
        
    }
    
};
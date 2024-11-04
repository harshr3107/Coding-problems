class Solution {
public:
    
    
    
    void getall(vector<int>& nums,vector<int>& v,set<vector<int>>& ans,vector<bool>& visited)
    {
        
        if(v.size()==nums.size())
        {
            ans.insert(v);
            return;
        }
        
        for(int i=0;i<nums.size();i++)
        {
            if(visited[i]==false)
            {
                visited[i]=true;
                v.push_back(nums[i]);
                getall(nums,v,ans,visited);
                v.pop_back();
                visited[i]=false;
            }
            
        }
        
        
    }
    
    
    
    
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
        vector<int> v;
        set<vector<int>> ans;
        vector<bool> visited(nums.size(),false);
        getall(nums,v,ans,visited);
        
        
        vector<vector<int>> a;
        
        for(auto it: ans)
        {
            a.push_back(it);
        }
        
        return a;
        
        
        
    }
};
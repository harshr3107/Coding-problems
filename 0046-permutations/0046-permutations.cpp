class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<int> v;
        vector<vector<int>> ans;
        map<int,int> m;
        
        getallpermutations(nums,v,ans,m);
        
        
        return ans;
        
    }



void getallpermutations(vector<int> nums,vector<int> v,vector<vector<int>>& ans,map<int,int> m)
{
    
    if(nums.size()==v.size())
    {
        ans.push_back(v);
        return;
    }   
    
    for(int i=0;i<nums.size();i++)
    {
        if(m.find(i)==m.end())
        {
            //cout<<"i entered here for "<<nums[i]<<endl;
            v.push_back(nums[i]);
            m[i]=1;
            getallpermutations(nums,v,ans,m);
            m.erase(i);
            v.pop_back();
        }
            
        
        
        
        
        
        
    }
        
    
    
}
    
    };
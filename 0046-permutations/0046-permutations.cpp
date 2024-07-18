class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        
        
        vector<vector<int>> ans;
       // map<int,int> m;
        
        //getallpermutations(nums,v,ans,m);
        
        getallpermutations(nums,0,ans);
        
        
        return ans;
        
    }
    
    
    
    void getallpermutations(vector<int>& nums,int ind,vector<vector<int>>& ans)
    {
        
        if(ind==nums.size())
        {
           ans.push_back(nums);
            return;
        }
        
       
        
        for(int i=ind;i<nums.size();i++)
        {
            swap(nums[ind],nums[i]);
            getallpermutations(nums,ind+1,ans);
            //ans.push_back(nums);
            swap(nums[ind],nums[i]);
            
            
            
            
        }
        
        
    }
    
    



/*void getallpermutations(vector<int> nums,vector<int> v,vector<vector<int>>& ans,map<int,int> m)
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
        
    
    
}*/
    
    };
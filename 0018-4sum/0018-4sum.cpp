class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        
        vector<vector<int>> ans;
        vector<int> v;
        long long sum=0;
        set<vector<int>> se;
       
        
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<nums.size();i++)
        {
            
            for(int j=i+1;j<nums.size()-1;j++)
            {
                sum=nums[i]+nums[j];
                
                long long h = target-sum;
                
                //cout<<"required h is "<<h<<endl;
                
                
                int x = j+1;
                int y = nums.size()-1;
                
                long long s = nums[x]+nums[y];
                
                //cout<<"value of s is "<<s<<endl;
                
                while(y>x)
                {
                
                    if(s==h)
                    {
                       // cout<<"i entered here\n";
                        
                        v.push_back(nums[i]);
                        v.push_back(nums[j]);
                        v.push_back(nums[x]);
                        v.push_back(nums[y]);
                        se.insert(v);
                        //cout<<"size of ans is "<<se.size()<<endl;
                        v.clear();
                    }
                    
                    
                    if(s>h)
                    {
                        s=s-nums[y];
                        y--;
                        s=s+nums[y];
                        
                    }else{
                        s=s-nums[x];
                        x++;
                        s=s+nums[x];
                    }
                    
                    
                    
                    
                    
                }
                
                
                
            }
            
            
            
        }
        
        for(auto it: se)
        {
            ans.push_back(it);
        }
        
        
        return ans;
        
        
    }
};
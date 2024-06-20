class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        vector<int> p;
        vector<vector<int>> ans;
        
       sort(nums.begin(),nums.end());
        
        
        int low=0;
        int high=nums.size()-1;
        
        
        int sum=0;
        int n = nums.size();
        
        
        for(int i=0;i<n-2;i++)
        {
            
            if(i==0 || nums[i]!=nums[i-1])
            {
                low=i+1;
                high=nums.size()-1;
                
                while(high>low)
                {
                    
                
                int sum=nums[i]+nums[low]+nums[high];
                
                    
                
                if(sum==0)
                {
                   // cout<<"i came here for "<<i<<" "<<low<<" "<<high<<endl;
                    
                    p.push_back(nums[i]);
                    p.push_back(nums[low]);
                    p.push_back(nums[high]);
                    
                    
                    
                    ans.push_back(p);
                    
                    p.clear();
                    
                    
                    
                    while( high>low && nums[low]==nums[low+1])
                    {
                        low++;
                    }
                    
                    while(high>low && nums[high]==nums[high-1] )
                    {
                       high--;
                    }
                    
                    low++;
                    high--;
                    
                    //cout<<"next is "<<i<<" "<<low<<" "<<high<<endl;
                    
                    
                }else if(sum>0){
                    
                    high--;
                    
                }else{
                    
                    low++;
                    
                }
                 }
                 }
            }
        
        
        return ans;
        
        
        
        
    }
};
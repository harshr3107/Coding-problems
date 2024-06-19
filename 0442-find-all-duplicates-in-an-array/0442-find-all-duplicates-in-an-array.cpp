class Solution {
public:
    vector<int> findDuplicates(vector<int> nums) {
        
        //sort(nums.begin(),nums.end());
       /* vector<int> visited(nums.size()+1,0);
        vector<int> ans;
        
        
        for(int i=0;i<nums.size();i++)
        {
            visited[nums[i]]++;
            if(visited[nums[i]]>1)
            {
                ans.push_back(nums[i]);
            }
        }
        
        return ans;
        */
        
        
        
        vector<int> ans;
        
        for(int i=0;i<nums.size();i++)
        {
            int a = abs(nums[i])-1;
            
            if(nums[a]<0)
            {
                ans.push_back(abs(nums[i]));
            }else{
                
                nums[a]=-nums[a];
            }
                
            
            
        }
        
        return ans;
        
        
        
    }
};
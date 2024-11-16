class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        
        vector<int> ans;
        
        if(k==1)
        {
            return nums;
        }
        
        int i=0;
        int j=0;
        
        while(i<=nums.size()-k)
        {
            int j=i;
            int a=1;
            while((j+1)<nums.size() && a<k)
            {
                if(nums[j]+1==nums[j+1])
                {
                    a++;
                }else{
                    break;
                }   
                
                j++;
                    
            }
            
            if(a==k)
            {
                ans.push_back(nums[j]);
               
            }else{
                ans.push_back(-1);
                
            }
            
            i++;
            
        }
        
        return ans;
        
        
    }
};
class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        
        int i=0;
        int j=0;
        vector<int> ans;
        
        while(i<=nums.size()-k)
        {
            
            j=i;
            int a=1;
            
            while(a!=k)
            {
                if(nums[j]+1!=nums[j+1])
                {
                    break;
                }
                
                j++;
                a++;
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
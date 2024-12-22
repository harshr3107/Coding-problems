class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        
        map<int,int> freq;
        
        int i=0;
        
        for(i=nums.size()-1;i>=0;i--)
        {
            if(freq[nums[i]]==1)
            {
                break;
            }
            
            freq[nums[i]]++;
            
        }
        
        
        i=i+1;
        
        int ans = i/3;
        
        if(i%3!=0)
        {
            ans+=1;
        }
        
        
        return ans;
        
        
    }
};
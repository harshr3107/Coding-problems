class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        vector<int>prefix(nums.size());
        vector<int> sufix(nums.size());
        
        vector<int> ans(nums.size());
        
        //prefix[0]=1;
        //sufix[nums.size()]=1;
        int pind=0;
        int sind=nums.size()-1;
        
        int prepro=1;
        int sufpro=1;
        
        int h=nums.size();
        
        
        for(int i=0;i<nums.size();i++)
        {
           prepro*=nums[i];
            sufpro*=nums[h-i-1];
             prefix[pind]=prepro;
            sufix[sind]=sufpro;
            pind++;
            sind--;
                
        }
        
       
        
        ans[0] = 1*sufix[1];
        ans[nums.size()-1] = 1*prefix[nums.size()-2];
        
        
        for(int i=1;i<nums.size()-1;i++)
        {
            ans[i]=prefix[i-1]*sufix[i+1];
        }
            
            
        return ans;
        
        
        
        
        
    }
};
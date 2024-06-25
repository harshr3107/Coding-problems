

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        
       /* int a = k%nums.size();
        
        while(a!=0)
        {
            int num = nums.back();
            nums.pop_back();
            nums.insert(nums.begin(),num);
            a--;
            
        }*/
        
        k=k%nums.size();
        
        
        /*vector<int>:: iterator it;
        
        it=nums.end()-(k);
       
        
        
        
        vector<int> v(it,nums.end());
        
        nums.erase(nums.end()-k,nums.end());
        
        vector<int> merged = v;
       merged.insert(merged.end(), nums.begin(), nums.end());
        
        nums=merged;*/
        
        
        vector<int> v(nums.size());
        
        for(int i=0;i<nums.size();i++)
        {
            v[(i+k)%nums.size()]=nums[i];
        }
           
        
        nums=v;
        
        
    }
};
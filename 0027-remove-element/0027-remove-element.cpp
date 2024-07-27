class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        
        int i=0;
        int j=nums.size()-1;
        
        int a=0;
        
        while(i<=j)
        {
            if(nums[i]==val)
            {
                a++;
                swap(nums[i],nums[j]);
                j--;
            }else{
                
                i++;
            }
            
            
      }
        
        
       return j+1;
        
        
        
    }
};
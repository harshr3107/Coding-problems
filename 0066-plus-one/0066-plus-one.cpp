class Solution {
public:
    vector<int> plusOne(vector<int>& nums) {
        
        int i = nums.size()-1;
        int num;
        int carry=1;
        
        
        while(i>=0)
        {
            num=nums[i]+carry;
            carry=0;
            
            if((num/10)!=0)
            {
                nums[i]=num%10;
                num=num/10;
                carry=num%10;
                i--;
                
            }else{
                nums[i]=num;
                break;
            }
            
            
            
            
        }
        
        if(carry!=0)
        {
            nums.insert(nums.begin(),carry);
            
        }
        
        
        return nums;
        
    }
};
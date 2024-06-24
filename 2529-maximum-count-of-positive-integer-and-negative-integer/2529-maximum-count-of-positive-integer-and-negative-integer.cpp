#include <algorithm>

class Solution {
public:
    int maximumCount(vector<int>& nums) {
        
        int low=0;
        int high=nums.size()-1;
        
        int mid=0;
        int ans=-1;
        int zcount=0;
        int n=0;
        int lpos=0;
        
        while(high>=low)
        {
            mid=low+(high-low)/2;
            if(nums[mid]>0)
            {
                
                
                ans=mid;
                high=mid-1;
                
                
            }else{
                
                low=mid+1;
            }
            
            
            
            
        }
        
        cout<<"The first pos integer is "<<ans<<endl;
        
        
            int i;
        
        
            if(ans==-1)
            {
                i=nums.size()-1;
            }else{
                i=ans-1;
            }
        
            int a=0;
            while(i>=0 && nums[i]==0)
            {
                i--;
                a++;
            }
        
        if(ans==-1)
        {
        return nums.size()-a;
            
        }
        
        int neg = ans-a;
        int pos = nums.size()-ans;
        
        if(neg>pos)
        {
            return neg;
        }
        
        
        return pos;
        
        
        
        
        
        
        

        
        
        
        
        
        
       
        
        
        
        
        
      
        
        
        
        
    }
};
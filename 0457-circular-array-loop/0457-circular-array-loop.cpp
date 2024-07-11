
class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        
        int low=0;
        int high=0;
        bool ans = false;
        int pos=0;
        int steps=0;
        int prehigh=-1;
        
        
        
        while(low<nums.size())
        {
            high=low;
            pos=0;
            if(nums[high]>0)
            {
                        pos++;
                        nums[high]=nums[high]%nums.size();
                        high=high+nums[high];
                        high=high%nums.size();
                
            
            }else{
                
                int temp=abs(nums[high])%(nums.size());
                high=high-temp;
              
                
                if(high<0)
                {
                    high=nums.size()+high;
                }
            }
            
            if(high==low)
            {
                low++;
                continue;
            }   
                
            map<int,int> mp;
            
            while(high<nums.size() && high!=low)
            {
                mp[high]++;
                
                if(pos>0 && nums[high]<0)
                {
                    break;
                }else if(pos==0 && nums[high]>0)
                {
                    break;
                }else{
                    
                    
                    if(pos>0)
                    {
                        nums[high]=nums[high]%nums.size();
                        high=high+nums[high];
                        high=high%nums.size();
                        
                     }else{
                        
                       int temp=abs(nums[high])%(nums.size());
                       high=high-temp;
                
                          if(high<0)
                          {
                            high=nums.size()+high;
                            }
                            
                    }
                   }
                
                if(high==low)
                {
                    ans=true;
                    return ans;
                }
                
                if(mp[high]==1)
                {
                    //return false;
                    break;
                }
         }
            
                   low++;
            
        }
        
        return ans;
    } 
    
};
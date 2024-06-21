class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
      int low=0;
      int high=nums.size()-1;
      int mid;
        vector<int> ans;
        int ind=-1;
        
        while(high>=low)
        {
            mid = low + (high-low)/2;
            
            if(nums[mid]==target)
            {
                ind=mid;
                break;
            }else if(nums[mid]>target)
            {
                high=mid-1;
                
            }else{
                low=mid+1;
            }
            
            
            
        
        }
        
        if(ind==-1)
        {
            ans.push_back(-1);
            ans.push_back(-1);
        }else{
            
            
            int temp=ind;
            int firstoccur=ind;
            int lastoccur=ind;
                
                while(ind<nums.size() && nums[ind]==target)
                {
                    ind++;
                }
                
                
                  ind--;
                  lastoccur = ind;
                
                
                
                
            
               ind=temp;
                
                while(ind>=0 && nums[ind]==target)
                {
                    ind--;
                }
                
               
                    ind++;
                    firstoccur=ind;
                    
            
                
                
                
                
            ans.push_back(firstoccur);
            ans.push_back(lastoccur);
            
            
            
        }
        
        
        return ans;
        
    }
};
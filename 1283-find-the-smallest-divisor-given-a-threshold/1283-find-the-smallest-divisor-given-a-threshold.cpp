class Solution {
public:
    
    bool ispossible(vector<int> nums,int th,int val)
    {
        
        
        int m=0;
        
        //cout<<"value of val is "<<val<<endl;
        
        for(int i=0;i<nums.size();i++)
        {
            m+=ceil(float(nums[i])/float(val));
            //cout<<"value of m is "<<m<<endl;
                
                if(m>th)
                {
                    return false;
                }
            
        }
        
        
        
        return true;
        
        
        
    }
    
    
    
    
    
    
    int smallestDivisor(vector<int>& nums, int threshold) {
        
        int max=INT_MIN;
        
        
        for(int i=0;i<nums.size();i++)
        {
            if(max<nums[i])
            {
                max=nums[i];
            }
        }
        
        
        int low=1;
        int high=max;
        int mid=0;
        int ans=max;
        
        while(high>=low)
        {
            mid = low+(high-low)/2;
            
            if(ispossible(nums,threshold,mid))
            {
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
            
            
        }
        
        
        return ans;
        
        
        
    }
};
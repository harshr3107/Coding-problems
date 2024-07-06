class Solution {
public:
    
    
    
    bool ispossibletoeatall(vector<int> nums,int h,int val)
    {
       int m=0;
        
        for(int i=0;i<nums.size();i++)
        {
            
            if(nums[i]%val!=0)
            {
               m=m+(nums[i]/val)+1;
            }else{
                m=m+nums[i]/val;
            }
            
           // cout<<"value of m is "<<m<<endl;
            
            if(m>h)
            {
                return false;
            }
            
            
        }
        
        if(m<=h)
        {
            return true;
            
        }
        
        
        return false;
        
        
        
        
        
    }
    
    
    
    int minEatingSpeed(vector<int>& piles, int h) {
        
        
        int max=INT_MIN;
        
        for(int i=0;i<piles.size();i++)
        {
            if(piles[i]>max)
            {
                max=piles[i];
            }
            
        }
        
        //
        
        
        
        int low=1;
        int high=max;
        int mid=0;
        int ans=max;
        
        while(high>=low)
        {
            
            mid = low+(high-low)/2;
            //cout<<"value of mid is "<<mid<<endl;
            
            if(ispossibletoeatall(piles,h,mid))
            {
                
                ans=mid;
                //cout<<"value of ans is "<<ans<<endl;
                high=mid-1;
            }else{
                
                low=mid+1;
            }
            
            
        }
        
        
        
        return ans;
        
        
        
    }
};
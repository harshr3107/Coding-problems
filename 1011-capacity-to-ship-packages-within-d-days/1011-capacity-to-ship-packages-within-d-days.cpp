class Solution {
public:
    
    
    bool ispossible(vector<int> arr,int days,int val)
    {
        int partion=0;
        int sum=0;
        int i=0;
        
        while(i<arr.size())
        {
            sum=sum+arr[i];
            
            if(sum>val)
            {
                partion++;
                if(partion>days-1 || arr[i]>val)
                {
                    return false;
                }
                sum=arr[i];
                
            }
            
            
            
            i++;
            
        }
        
        return true;
        
        
        
    }
    
    
    
    
    
    int shipWithinDays(vector<int>& weights, int days) {
        
        int sum=0;
        for(int i=0;i<weights.size();i++)
        {
            sum+=weights[i];
        }
        int low=0;
        int high=sum;
        int mid;
        int ans=-1;
        
        while(high>=low)
        {
            mid=low+(high-low)/2;
            
            if(ispossible(weights,days,mid))
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
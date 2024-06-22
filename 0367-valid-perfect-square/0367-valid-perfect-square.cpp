class Solution {
public:
    bool isPerfectSquare(int num) {
        
        if(num==1)
        {
            return true;
        }
        
        int low=0;
        int high=num-1;
        long long mid=0;
        bool ans=false;
        
        while(high>=low)
        {
            mid = low+(high-low)/2;
            
            if(mid*mid==num)
            {
                ans=true;
                return ans;
            }else if(mid*mid<num)
            {
                low=mid+1;
                
            }else{
                
                high=mid-1;
                
            }

        
        }
        
        
        return ans;
        
        
        
    }
};
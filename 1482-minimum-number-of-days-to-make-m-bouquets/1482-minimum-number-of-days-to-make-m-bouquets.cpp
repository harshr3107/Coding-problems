class Solution {
public:
    
    
   
    
    
    
 
    bool ispossible(vector<int>& bloomDay, int m, int k, int day) {
        int total = 0;
        for (int i = 0; i < bloomDay.size(); i++) {
            int count = 0;
            while (i < bloomDay.size() && count < k && bloomDay[i] <= day) {
                count++;
                i++;
            }

            if (count == k) {
                total++;
                i--;
            }

            if (total >= m) {
                return true;
            }
        }

        return false;
    }
    
    
    
    
    
    
    int minDays(vector<int>& bd, int m, int k) {
        
        
        if(bd.size()<(long)m*k)
        {
            return -1;
        }
        
        
       
        
        /*for(int i=0;i<bd.size();i++)
        {
            maxi=max(maxi,bd[i]);
        }*/
        
        int low=1;
        int high= *max_element(bd.begin(),bd.end());
        int mid;
        int ans=-1;
        
        while(high>low)
        {
            
            mid=low+(high-low)/2;
            
            if(ispossible(bd,m,k,mid))
            {
                ans=mid;
                high=mid;
            }else{
                low=mid+1;
            }
            
         }
        
     
        return low;
        
    }
};
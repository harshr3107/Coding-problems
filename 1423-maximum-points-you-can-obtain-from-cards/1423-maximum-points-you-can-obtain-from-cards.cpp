class Solution {
public:
    int maxScore(vector<int>& cp, int k) {
        
         int curk=0;
         int low=0;
         int high=cp.size()-1;
        int sum=0;
        int maxsum = INT_MIN;
        int csum=0;
        
        for(int i=0;i<cp.size();i++)
        {
            sum+=cp[i];
        }
        
        
        for(int i=0;i<cp.size()-k;i++)
        {
            csum+=cp[i];
        }
          
        //maxsum =max(mxsum,sum);
        
        maxsum = max(maxsum,sum-csum);
        high=cp.size()-k;
        
        
        
         while(high<cp.size())
         {
             
             csum-=cp[low];
             low++;
             csum+=cp[high];
             high++;
             maxsum=max(maxsum,sum-csum);
             
             
             
             
         }
        
        
        return maxsum;
        
    }
};
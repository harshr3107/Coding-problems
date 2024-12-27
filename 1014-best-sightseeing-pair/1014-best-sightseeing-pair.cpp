class Solution {
public:
    
    
   \
    
    
    
    
    int maxScoreSightseeingPair(vector<int>& values) {
        
      /*  int ans=INT_MIN;
        
        priority_queue<int> maxheap;
        
        for(int i=0;i<values.size()-1;i++)
        {
            int cur = values[i];
            for(int j=i+1;j<values.size();j++)
            {
                
                maxheap.push(cur+values[j]+(i-j)); 
                
            }
            
        }
        */
         
        int maxi = values[0]+0;
        int ans=0;
       
       for(int i=1;i<values.size();i++)
       {
           
           ans = max(ans,maxi+values[i]-i);
           maxi = max(maxi,values[i]+i);
       }
        
       return ans;
       
        
    }
};
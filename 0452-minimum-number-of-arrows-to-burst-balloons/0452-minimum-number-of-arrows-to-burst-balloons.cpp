class Solution {
public:
    
    
    bool static comp(vector<int>& a,vector<int>& b)
    {
        if(a[0]==b[0])
        {
            return a[1]>b[1];
        }
        
        return a[0]<b[0];
            
    }
  
    
    
    
   
    
    int findMinArrowShots(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(),intervals.end(),comp);
        
         pair<int,int> mini;
         int ans=0;
        
        
        
        
        for(int i=0;i<intervals.size();i++)
        {
           // cout<<intervals[i][0]<<" "<<intervals[i][1]<<endl;
            //cout<<"val of ans is "<<ans<<endl;
            
            if(i!=0 && ((mini.first<=intervals[i][0] && mini.second>=intervals[i][0])) )
            {
                mini.first = max(mini.first,intervals[i][0]);
                mini.second = min(mini.second,intervals[i][1]);
                
               continue;
            }
    
            
            //min=intervals[i][1];
            mini.first=intervals[i][0];
            mini.second=intervals[i][1];
            ans++;
            
        }
        
       
        
       
            
        
        
        
        return ans;
        
    }
};
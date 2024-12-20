class Solution {
public:
    
    
    class compare{
        
        public:
        
        bool operator()(pair<int,int>& a,pair<int,int>& b)
        {
            return a.second<b.second;
        }
        
        
    };
    
    
    
    
    
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(),intervals.end());
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,compare> minheap;
        
       
        for(int i=0;i<intervals.size();i++)
        {
            
            if(!minheap.empty() && minheap.top().second>intervals[i][0])
            {
                pair<int,int> temp = minheap.top();
                minheap.pop();
                
                minheap.push(make_pair(temp.first,min(intervals[i][1],temp.second)));
                
                continue;
            }
            
            minheap.push(make_pair(intervals[i][0],intervals[i][1]));
         
            
            
        }
        
        
        return intervals.size()-minheap.size();
        
      
            
        
    }
};
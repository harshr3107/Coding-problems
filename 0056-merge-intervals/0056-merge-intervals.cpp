class Solution {
public:
    
    
    class compare
    {
        
        public:
        
         static bool operator()(pair<int,int>& a,pair<int,int>& b)
         {
             return a.second<b.second;
         }
        
        
    };
    
    
    
    
    
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(),intervals.end());
        
        vector<vector<int>> ans;
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,compare> mh;
        
        for(int i=0;i<intervals.size();i++)
        {
            if(!mh.empty() && mh.top().second>=intervals[i][0])
            {
                pair<int,int> temp = mh.top();
                mh.pop();
                mh.push(make_pair(temp.first,max(intervals[i][1],temp.second)));
                continue;
            }else{
                
                mh.push(make_pair(intervals[i][0],intervals[i][1]));
                
            }
          
        }
        
        vector<int> v;
        
        while(!mh.empty())
        {
            
            v.push_back(mh.top().first);
            v.push_back(mh.top().second);
            ans.push_back(v);
            v.clear();
            mh.pop();
        }
        
        return ans;
        
        
        
        
        
        
    }
};
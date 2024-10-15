class Solution {
public:
    
    class compare{
      
        public:
        
        static bool operator()(pair<int,int>& a,pair<int,int>& b)
        {
            return a.second<b.second;
        }
        
    };
    
    
    
    
    
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(),intervals.end());
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,compare> mh;
        
        for(int i=0;i<intervals.size();i++)
        {
            if(!mh.empty() && mh.top().second>intervals[i][0])
            {
                pair<int,int> temp = mh.top();
                mh.pop();
                mh.push(make_pair(temp.first,min(temp.second,intervals[i][1])));
                continue;
            }
            
            mh.push(make_pair(intervals[i][0],intervals[i][1]));
            
        }
        
      /* while(!mh.empty())
        {
            cout<<mh.top().first<<" "<<mh.top().second<<endl;
            mh.pop();
        }
        
        cout<<endl;*/
        
        return intervals.size()-mh.size();
        
    }
};
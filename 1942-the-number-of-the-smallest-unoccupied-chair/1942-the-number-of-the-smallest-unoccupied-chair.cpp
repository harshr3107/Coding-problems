class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int t) {
        
        map<pair<int,int>,int> mp;
        
        for(int i=0;i<times.size();i++)
        {
            int u=times[i][0];
            int v = times[i][1];
            mp[make_pair(u,v)]=i;
        }
        
        
        
        
        //create 2 heaps one to share
        
       priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> mh;
       priority_queue<int,vector<int>,greater<int>> mh2;
        
       for(auto it: mp)
       {
           int u = it.first.first;
           int v = it.first.second;
           int j = it.second;
           
           int achair=INT_MAX;
           
           if(mh.empty() || mh.top().first<=u)
           {
              // cout<<"i entered here for "<<j<<endl;
               
               while(!mh.empty() && mh.top().first<=u)
               {
                   mh2.push(mh.top().second);
                   mh.pop();
               }
               
           }
           
           
           if(!mh2.empty())
           {
               mh.push(make_pair(v,mh2.top()));
               achair = mh2.top();
               mh2.pop();
             
           }else{
               
               int a = mh.size();
               achair=a;
               mh.push(make_pair(v,a));
               
           }
           
           
           //cout<<j<<" is given chair "<<achair<<endl;
           
           if(j==t)
           {
               return achair;
           }
           
           
       }
        
        
        
        
        
        return 1;
        
        
        
    }
};
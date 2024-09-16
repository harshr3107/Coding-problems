class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        //create a graph
        
        vector<vector<pair<int,int>>> adj(n+1);
        
        
        for(int i=0;i<times.size();i++)
        {
            int u = times[i][0];
            int v = times[i][1];
            int w = times[i][2];
            
            adj[u].push_back(make_pair(v,w));
            
        }
        
        
        
        //make a dist vector and a set wgich would help to keep the min dis at top
        
        vector<int> dist(n+1,INT_MAX);
        
        set<pair<int,int>> s;
        s.insert(make_pair(0,k));
        dist[k]=0;
        
        
        while(!s.empty())
        {
            //cout<<"i am here\n";
            
            int dis = (*s.begin()).first;
            int current = (*s.begin()).second;
            s.erase(s.begin());
            
            //cout<<dis<<" "<<current<<endl;
            
            
            for(int i=0;i<adj[current].size();i++)
            {
                if((dis+adj[current][i].second)<dist[adj[current][i].first])
                {
                    //cout<<"mai yaha aaya\n";
                     auto it = s.find(make_pair(dist[adj[current][i].first],adj[current][i].first));
                     dist[adj[current][i].first]=dis+adj[current][i].second;
                    
                    if(it!=s.end())
                    {
                    s.erase(it);
                    }
                    
                    s.insert(make_pair(dis+adj[current][i].second,adj[current][i].first));
                    
                }
                
                //cout<<"dhdhdhdh\n";
                
            }
            
            //cout<<"mai yah ape bhi aagaya\n";
            
        }
        
        int ans=INT_MIN;
        
        for(int i=1;i<dist.size();i++)
        {
            
            ans = max(ans,dist[i]);
        }
        
        if(ans==INT_MAX)
        {
            return -1;
        }
        
        return ans;
        
    }
};
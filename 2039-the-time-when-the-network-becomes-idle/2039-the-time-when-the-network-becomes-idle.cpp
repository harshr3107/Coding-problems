class Solution {
public:
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& p) {
        
        //create a graph first;
        
        vector<vector<int>> adj(p.size());
        
        for(int i=0;i<edges.size();i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
            
            
        }
        
    //using djikstra find the min distance from the mastre to the server
        
        vector<int> dis(p.size(),INT_MAX);
        dis[0]=0;
        
        set<pair<int,int>> s;
        s.insert(make_pair(0,0));
        
        
        while(!s.empty())
        {
            
            pair<int,int> temp = *(s.begin());
            s.erase(s.begin());
            
          int dist = temp.first;
          int node = temp.second;
            
            
            for(int i=0;i<adj[node].size();i++)
            {
                
                if(dist+1<dis[adj[node][i]])
                {
                    if(s.count(make_pair(dis[adj[node][i]],adj[node][i])))
                    {
                        s.erase(s.find(make_pair(dis[adj[node][i]],adj[node][i])));
                    }
                    
                    
                    dis[adj[node][i]]=dist+1;
                    
                    s.insert(make_pair(dist+1,adj[node][i]));
                }
                
                
            }
            
        }
        
        
        int ansmax=0;
       
      
        
        //vector<>
        
        
        for(int i=1;i<dis.size();i++)
        {
            int extraPayload = (dis[i]*2 - 1)/p[i]; 
			// extra number of payload before the first message arrive back to data server.
			// since a data server can only send a message before first message arrives back."
			// and first message arrives at time[i]*2. so "(time[i]*2-1)"
			
            int lastOut = extraPayload * p[i]; // find the last time when a data server sends a message
            int lastIn = lastOut + dis[i]*2; // this is the result for current data server
			
            ansmax = max(ansmax, lastIn);
            
        }
        
       
        
        
        
        return ansmax+1;
        
        
        
        
        
        
        
    }
};
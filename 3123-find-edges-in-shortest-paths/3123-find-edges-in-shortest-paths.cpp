/*class Solution {
public:
    
    
    void setupdate(vector<int> v,set<pair<int,int>>& se)
    {
        for(int i=0;i<v.size()-1;i++)
        {
            se.insert(make_pair(v[i],v[i+1]));
        }
        
      
    }
    
    
    
   //now create a function which checks if the given edges can be part of any shortrest dis or not
    
    
    void findans(vector<vector<pair<int,int>>>& adj,set<pair<int,int>>& se,int cur,vector<int>& v,int d,int csum,int n)
    {
        
        //cout<<"now the csum is "<<csum<<" and the req sum is "<<d<<endl;
        
        if(csum>d)
        {
            return;
        }
        
        if(csum==d && cur==n)
        {
            
            setupdate(v,se);
            
            return;
        }
        
        for(int i=0;i<adj[cur].size();i++)
        {
            csum+=adj[cur][i].second;
            v.push_back(adj[cur][i].first);
            findans(adj,se,adj[cur][i].first,v,d,csum,n);
            v.pop_back();
            csum-=adj[cur][i].second;
        }
        
        
    }
    
    
    
    
    
    
    vector<bool> findAnswer(int n, vector<vector<int>>& edges) {
        
        
        //create a adjancy List
        
        
        
        vector<vector<pair<int,int>>> adj(n);
        set<pair<int,int>> se;
        
        for(int i=0;i<edges.size();i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            
            adj[u].push_back(make_pair(v,wt));
            adj[v].push_back(make_pair(u,wt));
        }
        
        
        
        //use djikstras algorithm to find the shortest path
        
        //make a distance array
        vector<int> dis(n,INT_MAX);
        dis[0]=0;
        //make a set to keep a track of east distance
        
        set<pair<int,int>> s;
        s.insert(make_pair(0,0));
        
        
        while(!s.empty())
        {
            
            pair<int,int> temp = *(s.begin());
            
            
            
            int dist = temp.first;
            int node = temp.second;
            
            s.erase(s.begin());
            
            for(int i=0;i<adj[node].size();i++)
            {
                int d = dist+adj[node][i].second;
                int neigh = adj[node][i].first;
                
               if(d<dis[neigh])
               {
                   if(s.count(make_pair(dis[neigh],neigh)))
                   {
                       s.erase(make_pair(dis[neigh],neigh));
                   }
                   
                   dis[neigh]=d;
                   
                   s.insert(make_pair(dis[neigh],neigh));
               }
                
                
                
            }
            
            
            
            
            
            
            
        }
        
       
        //let the distnce has been found via djikstra
        
        int d = dis[n-1];
         vector<bool> ans(edges.size(),false);
        if(d==INT_MAX)
        {
            return ans;
        }
        
        
       
        vector<int> v;
        v.push_back(0);
        int csum=0;  
        
        //cout<<"value of n is "<<n<<endl<<endl<<endl;
        
        
        findans(adj,se,0,v,d,csum,n-1);
        
       
       
       
          
        
        for(int i=0;i<edges.size();i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            
            if(se.count(make_pair(u,v)) || se.count(make_pair(v,u)))
            {
                ans[i]=true;
            }
            
        }
        
        
        return ans;
        
         
        
    }
};*/

class Solution {
public:
    vector<bool> findAnswer(int n, vector<vector<int>>& edges) {
        // Create an adjacency list
        vector<vector<pair<int,int>>> adj(n);
        
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            
            adj[u].push_back(make_pair(v, wt));
            adj[v].push_back(make_pair(u, wt));
        }
        
        // Dijkstra's algorithm
        vector<int> dis(n, INT_MAX);
        vector<vector<int>> parents(n);  // Track parents for each node
        dis[0] = 0;
        
        set<pair<int, int>> s;  // Distance, node
        s.insert({0, 0});
        
        while (!s.empty()) {
            auto [dist, node] = *(s.begin());
            s.erase(s.begin());
            
            for (auto& [neigh, weight] : adj[node]) {
                int new_dist = dist + weight;
                
                if (new_dist < dis[neigh]) {
                    s.erase({dis[neigh], neigh});
                    dis[neigh] = new_dist;
                    s.insert({new_dist, neigh});
                    
                    // Update the parent list with a new shorter path
                    parents[neigh].clear();
                    parents[neigh].push_back(node);
                } else if (new_dist == dis[neigh]) {
                    // Add node to parent list for ties (multiple shortest paths)
                    parents[neigh].push_back(node);
                }
            }
        }
        
        // If no path exists, return all false
        vector<bool> ans(edges.size(), false);
        if (dis[n-1] == INT_MAX) return ans;
        
        // Backtrack to find all shortest path edges using BFS
        set<pair<int, int>> shortestPathEdges;
        queue<int> q;
        q.push(n - 1);
        vector<bool> visited(n, false);
        visited[n-1] = true;

        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            
            for (int parent : parents[cur]) {
                shortestPathEdges.insert({min(cur, parent), max(cur, parent)});
                
                if (!visited[parent]) {
                    visited[parent] = true;
                    q.push(parent);
                }
            }
        }
        
        // Mark the edges in the answer
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            
            if (shortestPathEdges.count({min(u, v), max(u, v)})) {
                ans[i] = true;
            }
        }
        
        return ans;
    }
};

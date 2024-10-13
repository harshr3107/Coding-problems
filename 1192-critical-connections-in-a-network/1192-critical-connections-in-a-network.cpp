class Solution {
public:
    
    void dfs(vector<vector<int>>& adj,int current,int parent,vector<int>& dis,vector<int>& low,int&
 timer,vector<vector<int>>& ans,vector<bool>& visited)
    {
        
        visited[current]=true;
        low[current]=timer;
        dis[current]=timer;
        
        timer++;
        
        for(int i=0;i<adj[current].size();i++)
        {
             if(parent==adj[current][i])
             {
                 continue;
             }
            
            if(!visited[adj[current][i]])
            {
                dfs(adj,adj[current][i],current,dis,low,timer,ans,visited);
                
                low[current] = min(low[current],low[adj[current][i]]);
                
                if(dis[current]<low[adj[current][i]])
                {
                    vector<int> v;
                    v.push_back(current);
                    v.push_back(adj[current][i]);
                    ans.push_back(v);
                    v.clear();
                    
                }
                
                
            }else{
                
                low[current] = min(low[current],low[adj[current][i]]);
            
            }
            
        }
        
        
        
        
        
        
    }
    
    
    
    
    
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        
        
        
        //Create A Adjancy List
        
        
        vector<vector<int>> adj(n);
        
        for(int i=0;i<connections.size();i++)
        {
            int u=connections[i][0];
            int v=connections[i][1];
            
            
            //edges are created
            
            adj[u].push_back(v);
            adj[v].push_back(u);
            
            
            
        }
        
        
        
        
        vector<int> dis(n,-1);
        vector<int> low(n,-1);
        vector<bool> visited(n,false);
        int timer=0;
        vector<vector<int>> ans;
        
        dfs(adj,0,-1,dis,low,timer,ans,visited);
        
        return ans;
        
        
    }
};
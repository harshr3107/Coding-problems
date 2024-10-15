class Solution {
public:
    
    
    void getdfs(vector<vector<pair<int,int>>>& adj,int current,int& mini,vector<bool>& visited)
    {
       // cout<<"i am the current "<<current<<endl;
        
       
        
        
       
        
        visited[current]=true;
       
        
        
        for(int i=0;i<adj[current].size();i++)
        {
             mini = min(mini,static_cast<int>(adj[current][i].second));
            if(visited[adj[current][i].first]==false)
            {
              //mini = min(mini,static_cast<int>(adj[current][i].second));
              getdfs(adj,adj[current][i].first,mini,visited);
            }
            
        }
        
        
        
    }
    
    
    
    
    
    
    
    
    
    int minScore(int n, vector<vector<int>>& roads) {
        
        //create a Adjancy List
        
        vector<vector<pair<int,int>>> adj(n+1);
        
        for(int i=0;i<roads.size();i++)
        {
            int u = roads[i][0];
            int v = roads[i][1];
            int t = roads[i][2];
            
            
            adj[u].push_back(make_pair(v,t));
            adj[v].push_back(make_pair(u,t));
            
            
            
        }
        
        
        
        /*Now we have create a adjancy List Now use dfs to travese from 1 to n ans see all possibe paths which are possible
         */
        vector<bool> visited(n,false);
        
        
        int mini = INT_MAX;
        
        getdfs(adj,1,mini,visited);
        
        
            return mini;    
        
        
    }
};
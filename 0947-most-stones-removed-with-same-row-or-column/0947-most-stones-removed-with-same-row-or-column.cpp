class Solution {
public:
    
    void dfs(int cur, unordered_map<int,vector<int>>& adj,unordered_map<int,bool>& vis)
    {
        vis[cur]=true;
        
        for(auto it: adj[cur])
        {
            if(vis[it]!=true)
            {
                dfs(it,adj,vis);
            }
        }
        
    }
    
    
    
    
    
    
    int removeStones(vector<vector<int>>& stones) {
        
        //create a graph
        
        unordered_map<int,vector<int>> adj;
        unordered_map<int,bool> vis;
        
        
        for(int i=0;i<stones.size();i++)
        {
              int u = stones[i][0];
              int v = stones[i][1];
            
               adj[u].push_back(v+10001);
               adj[v+10001].push_back(u);
              
             
        }
        
        int components=0;
        
        for(auto it : adj)
        {
            if(vis[it.first]==false)
            {
                dfs(it.first,adj,vis);
                components++;
                
            }
           
        }
        
        
        
        return stones.size()-components;
        
        
        
        
        
        
        
    }
};
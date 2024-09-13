class Solution {
public:
    
    void dfs(vector<vector<int>> adj,unordered_map<int,bool>& visited,int current)
    {
        
        
        visited[current]=true;
        
        for(int i=0;i<adj[current].size();i++)
        {
            if(!visited[adj[current][i]])
            {
                dfs(adj,visited,adj[current][i]);
            }
            
        }
        
    }
    
    
    
    
    
    int findCircleNum(vector<vector<int>>& isconnected) {
        
        unordered_map<int,bool> visited(isconnected.size());
        
        vector<vector<int>> adj(isconnected.size());
        
        for(int i=0;i<isconnected.size();i++)
        {
            for(int j=0;j<isconnected[i].size();j++)
            {
                if(isconnected[i][j]==1 && i!=j)
                {
                    adj[i].push_back(j);
                }
            }
        }
        
       // display(adj);
        
        int ans=0;
        
        for(int i=0;i<isconnected.size();i++)
        {
            if(!visited[i])
            {
                ans++;
                dfs(adj,visited,i);
            }
            
        }
        
        
        return ans;
        
    }
};
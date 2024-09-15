class Solution {
public:
    
    
    
    bool checkdfscycle(vector<vector<int>>& adj,vector<bool>& visited,vector<bool>& dfsvisited,int current)
    {
        
       // cout<<"i am here for "<<current<<endl;
        
        visited[current]=true;
        dfsvisited[current]=true;
        
        
        for(int i=0;i<adj[current].size();i++)
        {
            if(!visited[adj[current][i]])
            {
                
                
                if(checkdfscycle(adj,visited,dfsvisited,adj[current][i])==true)
                {
                    return true;
                }
            }else if(dfsvisited[adj[current][i]])
            {
                return true;
            }
            
        }
        
        dfsvisited[current]=false;
        
        
        return false;
        
        
        
    }
    
    
    
    bool canFinish(int v, vector<vector<int>>& edges) {
        
        //Make the graph
        
        vector<vector<int>> adj(v);
        
        for(int i=0;i<edges.size();i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            
            adj[v].push_back(u);
        }
        
        
        //now check if cycle exists;
        
        vector<bool> visited(v,false);
        vector<bool> dfsvisited(v,false);
        
        for(int i=0;i<v;i++)
        {
            if(!visited[i])
            {
                if(checkdfscycle(adj,visited,dfsvisited,i)==true)
                {
                   // cout<<"i came here for "<<i<<endl;
                    return false;
                }
                
            }
        }
        
        
        return true;
        
    }
};
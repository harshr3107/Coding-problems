class Solution {
public:
    
    
    int getshortestdis(vector<vector<int>>& adj,int n)
    {
        
         set<pair<int,int>> s;
        
         vector<int> dis(n+1,INT_MAX);
        
         s.insert(make_pair(0,0));
         dis[0]=0;
        
        while(!s.empty())
        {
            
            int dist = s.begin()->first;
            int temp = s.begin()->second;
            s.erase(*(s.begin()));
            
            
            for(int i=0;i<adj[temp].size();i++)
            {
                
                if((dist+1)<dis[adj[temp][i]])
                {
                    
                    //delete the exisiting dis
                   if(s.count(make_pair(dis[adj[temp][i]],adj[temp][i])))
                   {
                       s.erase(make_pair(dis[adj[temp][i]],adj[temp][i]));
                   }
                    
                    s.insert(make_pair(dist+1,adj[temp][i]));
                    dis[adj[temp][i]]=dist+1;
                    
                    
                }
                
                
            }
                 
            
            
        }
        
        return dis[n-1];
        
    }
    
    
    
    
    
    
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        
        vector<vector<int>> adj(n);
        
        for(int i=0;i<(n-1);i++)
        {
            adj[i].push_back(i+1);
        }
        
        vector<int> ans;
        
        for(int k=0;k<queries.size();k++)
        {
        
            int i=queries[k][0];
            int j = queries[k][1];
        
           adj[i].push_back(j);
        
           ans.push_back(getshortestdis(adj,n));
            
        }
        
        
        
        return ans;
        
       
        
        
    }
};
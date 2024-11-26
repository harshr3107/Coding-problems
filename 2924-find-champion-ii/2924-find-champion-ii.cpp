class Solution {
public:
    
    
    
    void gettropo(vector<vector<int>>& adj,int current,vector<bool>& visited,stack<int>& st)
    {
        visited[current]=true;
        
        for(int i=0;i<adj[current].size();i++)
        {
            if(visited[adj[current][i]]==false)
            {
                gettropo(adj,adj[current][i],visited,st);
            }
        }
        
         st.push(current);                     
        
        
        
    }
    
    
    int findChampion(int n, vector<vector<int>>& edges) {
        
        //we need to perform tropological sort
        
       // vector<vector<int>> adj(n);
        vector<int> indegree(n,0);
        
        for(int i=0;i<edges.size();i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            
            indegree[v]+=1;
            
            //adj[u].push_back(v);
        }
        
        
        /*vector<bool> visited(n,false);
        stack<int> st;
        
        for(int i=0;i<n;i++)
        {
            
            if(visited[i]==false)
            {
              gettropo(adj,i,visited,st);
        
                  while(!st.empty())
                   {
                       cout<<st.top()<<" ";
                        st.pop();
                   }
                 cout<<endl;
            }
            
           
        }*/
        
        int a=0;
        int ans=-1;
        
        for(int i=0;i<n;i++)
        {
            if(indegree[i]==0)
            {
                a++;
                ans=i;
                
            }
        }
        
        if(a>=2)
        {
            return -1;
        }
        
       
        
        return ans;
        
    }
};
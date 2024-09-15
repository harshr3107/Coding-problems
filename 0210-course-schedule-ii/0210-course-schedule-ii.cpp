class Solution {
public:
    
    bool gettropsort(vector<vector<int>>& adjlist,vector<bool>& visited,stack<int>& st,int current,vector<bool> dfsvisited)
    {
        
        visited[current]=true;
        dfsvisited[current]=true;
        
        
        
        for(int i=0;i<adjlist[current].size();i++)
        {
            
            if(!visited[adjlist[current][i]])
            {
                if(gettropsort(adjlist,visited,st,adjlist[current][i],dfsvisited)==true)
                {
                    return true;
                }
            }else if(dfsvisited[adjlist[current][i]])
            {
                return true;
            }
            
        }
        
        st.push(current);
        
        
        return false;
        
        
        
        
    }
    
    
    
    
    
    vector<int> findOrder(int n, vector<vector<int>>& edges) {
        
        //first create a rph using adjancy list
        
          vector<vector<int>> adjlist(n);
        
          for(int i=0;i<edges.size();i++)
          {
              int u = edges[i][0];
              int v = edges[i][1];
              
              adjlist[v].push_back(u);
          }
        
          
          
         vector<bool> visited(n,false);
         vector<bool> dfsvisited(n,false);
         vector<int> ans;
         stack<int> st;
        
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                if(gettropsort(adjlist,visited,st,i,dfsvisited)==true)
                {
                    return ans;   
                }
            }
            
        }
        
        
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        
        
        return ans;
        
        
        
        
        
    }
};
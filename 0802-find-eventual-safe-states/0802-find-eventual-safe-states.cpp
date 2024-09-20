class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        
        
        // we will have to first recerse a graph
        
        vector<vector<int>> adjrev(graph.size());
        vector<int> indegree(graph.size(),0);
        
        for(int i=0;i<graph.size();i++)
        {
            for(int j=0;j<graph[i].size();j++)
            {
                
                adjrev[graph[i][j]].push_back(i);
                indegree[i]+=1;
                
                
            }
        }
        
        
        
       queue<int> q;
        vector<int> ans;
        vector<bool> visited(graph.size(),false);
        
        
        for(int i=0;i<adjrev.size();i++)
        {
            //cout<<indegree[i]<<" ";
            
            if(indegree[i]==0)
            {
                visited[i]=true;
                q.push(i);
            }   
                
        }
        
        
       // cout<<endl;
           
        
       while(!q.empty())
        {
           //cout<<q.size()<<endl;
            
            int temp = q.front();
            q.pop();
            ans.push_back(temp);
            
            for(int i=0;i<adjrev[temp].size();i++)
            {
                //cout<<"here val of neigh is "<<adjrev[temp][i]<<endl;
                
                if(!visited[adjrev[temp][i]])
                {
                    //cout<<"mai ander aaya\n";
                   // cout<<indegree[adjrev[temp][i]]<<endl;
                    
                    indegree[adjrev[temp][i]]-=1;
                     
                cout<<indegree[adjrev[temp][i]]<<endl;
                        
                    if(indegree[adjrev[temp][i]]==0)
                    {
                        //cout<<"idhar ghusa\n";
                        visited[adjrev[temp][i]]=true;
                        q.push(adjrev[temp][i]);
                    }
                }
                
                
            }
            
            
            
            
            
        }
        
        
        sort(ans.begin(),ans.end());
        
        
        return ans;
        
        
        
        
        
    }
};
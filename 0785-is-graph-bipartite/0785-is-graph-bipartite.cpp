class Solution {
public:
    
    bool getdfs(vector<vector<int>>& graph,vector<bool>& visited,vector<int>& color,int current,int col)
    {
        
        visited[current]=true;
        
        int temp;
         
        if(col==1)
        {
            temp=0;
        }else{
            temp=1;
        }
        
        
        for(int i=0;i<graph[current].size();i++)
        {
            
            
          if(!visited[graph[current][i]])
          {
                            
              color[graph[current][i]]=temp;
              if(getdfs(graph,visited,color,graph[current][i],temp)==false)
              {
                 return false;   
              }
                       
          }else{
              
              if(color[graph[current][i]]==col)
              {
                return false;
              }
              
          }
                      
        }
        
        
        
        return true;
        
                       
        
        
        
        
    }
    
    
    
    
    
    
    
    
    
    bool isBipartite(vector<vector<int>>& graph) {
        
        vector<int> color(graph.size(),-1);
        vector<bool> visited(graph.size(),false);
        
        
         for(int i=0;i<graph.size();i++)
         {
             if(!visited[i])
             {
                 color[i]=0;
                 if(getdfs(graph,visited,color,i,0)==false)
                 {
                     return false;
                 }
                 
                 
             }
             
         }
        
        
        
        return true;
        
        
    }
};
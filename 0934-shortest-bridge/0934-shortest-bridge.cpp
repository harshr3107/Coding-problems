class Solution {
public:
    
    
    
    void dfs(vector<vector<int>>& grid,int i,int j,vector<vector<bool>>& visited, set<pair<int,pair<int,int>>>& s)
    {
        //cout<<"mai yaha aaya tha for "<<i<<" "<<j<<endl;
        
        s.insert(make_pair(0,make_pair(i,j)));
        visited[i][j]=true;
        
        
        if((i-1)>=0 && grid[i-1][j]==1 && visited[i-1][j]==false)
        {
            dfs(grid,i-1,j,visited,s);
        }
         if((i+1)<grid.size() && grid[i+1][j]==1 && visited[i+1][j]==false) 
        {
            dfs(grid,i+1,j,visited,s);
        }
        
         if((j-1)>=0 && grid[i][j-1]==1 && visited[i][j-1]==false)
        {
            dfs(grid,i,j-1,visited,s);
        }
        
        if((j+1)<grid[i].size() && grid[i][j+1]==1 && visited[i][j+1]==false) 
        {
            dfs(grid,i,j+1,visited,s);
        }
        
        
        
        
    }
    
    
    
    
    int shortestBridge(vector<vector<int>>& grid) {
        
        
        vector<vector<bool>> visited;
        
        for(int i=0;i<grid.size();i++)
        {
            vector<bool> v(grid[i].size(),false);
            visited.push_back(v);
        }
        
       set<pair<int,pair<int,int>>> s;
        
        for(int i=0;i<grid.size();i++)
        {
            int a=0;
            
            for(int j=0;j<grid[i].size();j++)
            {
                
            
             if(grid[i][j]==1)
             {
                 a++;
                dfs(grid,i,j,visited,s);
                break;
             }
                
            }
            if(a!=0)
            {
                break;
            }
        }
        
        //cout<<"the size of the set is "<<s.size()<<endl;
        
        
        while(!s.empty())
        {
            
            pair<int,pair<int,int>> temp = *(s.begin());
            int level = temp.first;
            int i = temp.second.first;
            int j = temp.second.second;
            
            //cout<<"i entered here for "<<i<<" and "<<j<<endl;
            
            s.erase(s.begin());
            
           
            
            
        if((i-1)>=0  && visited[i-1][j]==false)
        {
            if(grid[i-1][j]==1)
            {
                return level;
            }else{
                
                visited[i-1][j]=true;
                s.insert(make_pair(level+1,make_pair(i-1,j)));
                
            }
            
        }
         if((i+1)<grid.size() && visited[i+1][j]==false) 
        {
            if(grid[i+1][j]==1)
            {
                return level;
            }else{
                
                visited[i+1][j]=true;
                s.insert(make_pair(level+1,make_pair(i+1,j)));
                
            }
            
        }
        
        if((j-1)>=0 && visited[i][j-1]==false)
        {
            
            if(grid[i][j-1]==1)
            {
                return level;
            }else{
                
                visited[i][j-1]=true;
                s.insert(make_pair(level+1,make_pair(i,j-1)));
                
            }
           
        }
        
        if((j+1)<grid[i].size() && visited[i][j+1]==false) 
        {
             if(grid[i][j+1]==1)
            {
                return level;
            }else{
                
                visited[i][j+1]=true;
                s.insert(make_pair(level+1,make_pair(i,j+1)));
                
            }
           
            
        }
            
          
    }
        
        
       
       return 0;    
        
        
    }
};
class Solution {
public:
    
    
    
    void dfs(vector<vector<char>>& grid,int cr,int cc,vector<vector<bool>>& visited)
    {
        
        visited[cr][cc]=true;
        
        
        if((cr-1)>=0 && grid[cr-1][cc]=='1' && visited[cr-1][cc]==false)
        {
            
            dfs(grid,cr-1,cc,visited);
        }
        
        
        
        
        if((cr+1)<grid.size() && grid[cr+1][cc]=='1' && visited[cr+1][cc]==false)
        {
            
            dfs(grid,cr+1,cc,visited);
        }
        
        
        
        
        if((cc-1)>=0 && grid[cr][cc-1]=='1' && visited[cr][cc-1]==false)
        {
            
            dfs(grid,cr,cc-1,visited);
        }
        
         if((cc+1)<grid[cr].size() && grid[cr][cc+1]=='1' && visited[cr][cc+1]==false)
        {
            
            dfs(grid,cr,cc+1,visited);
        }
        
        
    }
    
    
    
    
    int numIslands(vector<vector<char>>& grid) {
        
        
        vector<vector<bool>> visited;
        
        for(int i=0;i<grid.size();i++)
        {
            vector<bool> v(grid[i].size(),false);
            visited.push_back(v);
        }
        
        int ans=0;
        
        for(int i=0;i<grid.size();i++)
        {
            
            for(int j=0;j<grid[i].size();j++)
            {
                if(grid[i][j]=='1' && visited[i][j]==false)
                {
                    ans++;
                    dfs(grid,i,j,visited);
                    
                }
            }
            
        }
        
        
        
        return ans;
        
        
        
        
        
    }
};
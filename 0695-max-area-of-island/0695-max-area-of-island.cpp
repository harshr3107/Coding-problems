class Solution {
public:
    
    void getbfs(vector<vector<int>>& grid,vector<vector<bool>>& visited,int cr,int cc,int& ans)
    {
        
        
        queue<pair<int,int>> q;
        q.push(make_pair(cr,cc));
        
        int count=0;
        
        while(!q.empty())
        {
            
            pair<int,int> temp = q.front();
            q.pop();
            count++;
            
            int row = temp.first;
            int col = temp.second;
            
            
            if((row-1)>=0 && grid[row-1][col]==1 && visited[row-1][col]==false)
            {
                visited[row-1][col]=true;
                q.push(make_pair(row-1,col));
                
            }
            
            
            if((row+1)<grid.size() && grid[row+1][col]==1 && visited[row+1][col]==false)
            {
                visited[row+1][col]=true;
                q.push(make_pair(row+1,col));
            }
            
            
            if((col-1)>=0 && grid[row][col-1]==1 && visited[row][col-1]==false)
            {
                visited[row][col-1]=true;
                q.push(make_pair(row,col-1));
                
            }
            
            
            if((col+1)<grid[row].size() && grid[row][col+1]==1 && visited[row][col+1]==false)
            {
                visited[row][col+1]=true;
                q.push(make_pair(row,col+1));
            }
                
            
            
            
            
        }
        
        
        
        ans = max(ans,count);
        
        
        
    }
    
    
    
    
    
    
    
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        
        vector<vector<bool>> visited;
        for(int i=0;i<grid.size();i++)
        {
            vector<bool> v(grid[i].size(),false);
            visited.push_back(v);
        }
        
        
        int ans = 0;
        
        
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[i].size();j++)
            {
                
                if(grid[i][j]==1 && visited[i][j]==false)
                {
                    visited[i][j]=true;
                    getbfs(grid,visited,i,j,ans);
                    
                }
                
            }
        }
        
        
        
        return ans;
        
        
    }
};
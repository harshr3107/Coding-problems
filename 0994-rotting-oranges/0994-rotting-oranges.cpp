class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        
        vector<vector<bool>> visited;
        
        for(int i=0;i<grid.size();i++)
        {
            vector<bool> v(grid[i].size(),false);
            visited.push_back(v);
        }
        
        
        
        queue<pair<pair<int,int>,int>> q;
        
        
        
        for(int i=0;i<grid.size();i++)
        {
           
            
            for(int j=0;j<grid[i].size();j++)
            {
                if(grid[i][j]==2)
                {
                    q.push(make_pair(make_pair(i,j),0));
                    visited[i][j]=true;
                }
                
                
            }
        }
            
            
            
            
            
            
            
            
            
           /* for(int i=0;i<visited.size();i++)
            {
                for(int j=0;j<visited[i].size();j++)
                {
                    cout<<visited[i][j]<<" ";
                }
                
                cout<<endl;
            }*/
        
        int ans = 0;
        
        
        while(!q.empty())
        {
            pair<pair<int,int>,int> temp = q.front();
            q.pop();
            int row = temp.first.first;
            int col = temp.first.second;
            int curtime = temp.second;
            ans=curtime;
            
            if((row-1)>=0)
            {
                if(grid[row-1][col]==1 && visited[row-1][col]==false)
                {
                    visited[row-1][col]=true;
                    grid[row-1][col]=2;
                    q.push(make_pair(make_pair(row-1,col),curtime+1));
                }
            }
            
            
            if((row+1)<grid.size())
            {
                if(grid[row+1][col]==1 && visited[row+1][col]==false)
                {
                    visited[row+1][col]=true;
                    grid[row+1][col]=2;
                    q.push(make_pair(make_pair(row+1,col),curtime+1));
                }
            }
            
            
            if((col-1)>=0)
            {
                
                if(grid[row][col-1]==1 && visited[row][col-1]==false)
                {
                    visited[row][col-1]=true;
                    grid[row][col-1]=2;
                    q.push(make_pair(make_pair(row,col-1),curtime+1));
                }
                
            }
            
            if((col+1)<grid[row].size())
            {
                if(grid[row][col+1]==1 && visited[row][col+1]==false)
                {
                    visited[row][col+1]=true;
                    grid[row][col+1]=2;
                    q.push(make_pair(make_pair(row,col+1),curtime+1));
                }
            }
            
            
            
            
            
            
        }
        
        
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[i].size();j++)
            {
                if(grid[i][j]==1)
                {
                    return -1;
                }
                
            }
        }
        
        
        
        
            
            
            
            
           
         return ans;
            
            
            
            
            
        }
        
    
        
       
        
    
};
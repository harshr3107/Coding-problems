class Solution {
public:
    
    void getdfs(vector<vector<char>>& grid,int cr,int cc,vector<vector<bool>>& visited)
    {
        
        visited[cr][cc]=true;
        
        
        if((cr-1)>=0 && grid[cr-1][cc]=='X' && visited[cr-1][cc]==false)
        {
            getdfs(grid,cr-1,cc,visited);
        }
        
        
        if((cr+1)<grid.size() && grid[cr+1][cc]=='X' && visited[cr+1][cc]==false)
        {
            getdfs(grid,cr+1,cc,visited);
        }
        
        
        
        if((cc-1)>=0 && grid[cr][cc-1]=='X' && visited[cr][cc-1]==false)
        {
            getdfs(grid,cr,cc-1,visited);
        }
        
        if((cc+1)<grid[cr].size() && grid[cr][cc+1]=='X' && visited[cr][cc+1]==false)
        {
            getdfs(grid,cr,cc+1,visited);
        }
        
        
        
    }
    
    
    
    
    
    int countBattleships(vector<vector<char>>& board) {
        
        
             int count=0;
             vector<vector<bool>> visited;
        
               for(int i=0;i<board.size();i++)
               {
                   vector<bool> v(board[i].size(),false);
                   visited.push_back(v);
               }
        
             
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[i].size();j++)
            {
                if(board[i][j]=='X' && visited[i][j]==false)
                {
                    count++;
                    getdfs(board,i,j,visited);
                    
                }
                
            }
            
        }
        
        
        
        return count;
        
        
        
        
        
    }
};
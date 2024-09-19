class Solution {
public:
    
    
    void dfs(vector<vector<char>>& board,int cr,int cc,vector<vector<bool>>& visited)
    {
        
         visited[cr][cc]=true;
        
        
         if((cr-1)>=0 && board[cr-1][cc]=='O' && visited[cr-1][cc]==false)
         {
             board[cr-1][cc]='y';
             dfs(board,cr-1,cc,visited);
             
         }
        
       
         if((cr+1)<board.size() && board[cr+1][cc]=='O' && visited[cr+1][cc]==false)
         {
             board[cr+1][cc]='y';
             dfs(board,cr+1,cc,visited);
             
         }
        
        
         if((cc-1)>=0 && board[cr][cc-1]=='O' && visited[cr][cc-1]==false)
         {
             board[cr][cc-1]='y';
             dfs(board,cr,cc-1,visited);
             
         }
      
        
         if((cc+1)<board[cr].size() && board[cr][cc+1]=='O' && visited[cr][cc+1]==false)
         {
             board[cr][cc+1]='y';
             dfs(board,cr,cc+1,visited);
             
         }
        
        
        
        
        
    }
    
    
    
    
    
    
    
    void solve(vector<vector<char>>& board) {
        
        
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
                
               
                if(i==0 || j==0 || i==board.size()-1 || j==board[i].size()-1)
               {
                    
                 if(board[i][j]=='O' && visited[i][j]==false)
                 {
                    // cout<<"i entered here for "<<i<<" "<<j<<endl;
                     board[i][j]='y';
                     dfs(board,i,j,visited); 
                    
                 }
                
                }
                
                
            }
            
        }
        
        
       
        for(int i=0;i<board.size();i++)
        {
        
            for(int j=0;j<board[i].size();j++)
            {
                
               if(board[i][j]=='O')
               {
                   board[i][j]='X';
               }else if (board[i][j]=='y')
               {
                   board[i][j]='O';
               }
                
                
                
            }
            
        }
        
        
        
        
        
        
        
    }
};
class Solution {
public:
    
    
    
    
    bool solve(vector<vector<char>>& board,int row,int col,int cd,string word,vector<vector<bool>>& visited)
    {
       
        
       
        
        if(cd==word.length())
        {
    
            return true;
        }
        
       if(row<0 || row>=board.size() || col<0 || col>=board[row].size() || word[cd]!=board[row][col] || visited[row][col]==true)
       {
           return false;
       }
        
        
       
       
            //cout<<"\ni am here for "<<row<<" "<<col<<endl;
            
            visited[row][col]=true;
            
           
            
               
                if(solve(board,row-1,col,cd+1,word,visited)==true)
                {
                    return true;
                }
                
                
                
            
        
                if(solve(board,row+1,col,cd+1,word,visited)==true)
                {
                    return true;
                }
             
               
        
                 if(solve(board,row,col-1,cd+1,word,visited)==true)
                 {
                     return true;
                 }
                
                
                
           
           
                 if(solve(board,row,col+1,cd+1,word,visited)==true)
                 {
                     return true;
                 }
            
        visited[row][col]=false;
        
        return false;
        
    }
        
    
    
    
    bool exist(vector<vector<char>>& board, string word) {
        
        
        if(board.size()==1 && board[0].size()==1)
        {
            if(word.at(0)!=board[0][0])
            {
                return false;
            }
        }
        
        
        vector<vector<bool>> visited(board.size());
        
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[i].size();j++)
            {
                visited[i].push_back(false);
            }
        }
        
       
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[i].size();j++)
            {
                if(board[i][j]==word[0])
                {
                    cout<<"\ni entered here  for "<<i<<" "<<j<<endl;
                    if(solve(board,i,j,0,word,visited)==true)
                    {
                        cout<<"\ni entered here  for "<<i<<" "<<j<<endl;
                        return true;
                    }
                    
                }
            }
        }
        
        
        
        
        return false;
        
        
    }
};
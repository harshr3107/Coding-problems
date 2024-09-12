class Solution {
public:
    
    
    
    
   /* bool issafe(vector<vector<char>>& board,int row,int col,string word,int curindex,vector<vector<bool>> visited)
    {
        
        if(row<0 || row>=board.size() || col<0 || col>=board[row].size() || curindex>=word.length() || visited[row][col]==true)
        {
            return false;
        }
        
        
        if(board[row][col]==word[curindex])
        {
            return true;
        }
        
        
        return false;
        
        
    }
    */
    
    
    
    
    bool checkforword(vector<vector<char>>& board,string word,int row,int col,vector<vector<bool>>& visited,int curindex)
    {
        //cout<<"i am here for "<<row<<" "<<col<<" the curindex is "<<curindex<<endl;
        
        if(curindex==word.length())
        {
            return true;
        }
        
        
        
       if(row<0 || row>=board.size() || col<0 || col>=board[row].size() || word[curindex]!=board[row][col] || visited[row][col]==true)
       {
           return false;
       } 
        
        visited[row][col]=true;
        
        
        
           if(checkforword(board,word,row+1,col,visited,curindex+1)==true)
            {
                return true;   
            }
       
            if(checkforword(board,word,row-1,col,visited,curindex+1)==true)
            {
               return true;   
            }
        
        
           if(checkforword(board,word,row,col+1,visited,curindex+1)==true)
            {
                return true;
            }
        
        
            if(checkforword(board,word,row,col-1,visited,curindex+1)==true)
            {
                return true;   
            }
        
        
        visited[row][col]=false;
        
        return false;
        
    }
    
    
    bool exist(vector<vector<char>>& board, string word) {
        
        
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
                if(board[i][j]==word[0])
                {
                    //cout<<"i entered here for "<<i<<" "<<j<<endl;
                    
                    if(checkforword(board,word,i,j,visited,0)==true)
                    {
                        return true;
                    }
                    
                }
                
            }
        }
        
        return false;
        
        
        
    }
};
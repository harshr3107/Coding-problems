class Solution {
public:
    
    bool issafe(vector<vector<char>>& board,int row,int col,char num)
    {
        
        for(int i=0;i<board.size();i++)
        {
             
            
            if(board[row][i]==num)
            {
               
                return false;
            }
            if(board[i][col]==num)
            {
                return false;
            }
            
        }
        
        int c=col/3;
        int r = row/3;
        
        for(int i=3*r;i<=(3*r+2);i++)
        {
            for(int j=3*c;j<=(3*c+2);j++)
            {
                if(board[i][j]==num)
                {
                   
                    return false;
                }
            }
            
        }
        
        
        
        
        return true;
    }
    
    
    vector<int> findemptyspace(vector<vector<char>>& board)
    {
        vector<int> v;
        
          for(int i=0;i<board.size();i++)
          {
              for(int j=0;j<board[i].size();j++)
              {
                  if(board[i][j]=='.')
                  {
                      v.push_back(i);
                      v.push_back(j);
                      return v;
                  }
                  
              }
              
          }
        
        return v;
        
    }
   
    
     bool solves(vector<vector<char>>& board)
    {
        vector<int> v;
        
        if(findemptyspace(board).empty())
        {
            return true;
        }
       
            v=findemptyspace(board);
            int row = v[0];
            int col=v[1];
        
        
            
           
            
            //cout<<"i am here for "<<row<<" "<<col<<endl;
            
            for(char i='1';i<='9';i++)
            {
                if(issafe(board,row,col,i))
                {
                     if(row==0 && col==2)
                     {
                           cout<<"value of i is "<<i<<endl;
                     }
                    board[row][col]=i;
                    if(solves(board)==true)
                    {
                        return true;
                    }
                    board[row][col]='.';
                }
                
            }
            
        
        
        return false;
        
        
    }
    
    
    
    
    
    
    void solveSudoku(vector<vector<char>>& board) {
        
        
        solves(board);
        
        
       
        
    }
};
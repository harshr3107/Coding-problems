class Solution {
public:
    
    
    int checklive(vector<vector<int>> board,int i,int j)
    {
        
        int a=0;
        
        if(i>0 && j>0)
        {
            if(board[i-1][j-1]==1)
            {
                a++;
            }
            
            if(board[i-1][j]==1)
            {
                a++;
            }    
                
            if(board[i][j-1]==1)
            {
                a++;
            }
            
            if(i<board.size()-1  && j<board[i].size()-1)
            {
                
                if(board[i+1][j+1]==1)
                {
                a++;
                }
                
            }
            
            
            if(i<board.size()-1)
            {
                
                if(board[i+1][j-1]==1)
                {
                    a++;
                }
                
                if(board[i+1][j]==1)
                {
                    a++;
                }
                
            }
            
            
            if(j<board[i].size()-1)
            {
                 if(board[i][j+1]==1)
                {
                    a++;
                }
                
                if(board[i-1][j+1]==1)
                {
                    a++;
                }
                
                
            }
             
            
            
          
                
            
        }else if(i>0)
        {
            if(board[i-1][j]==1)
            {
                a++;
            } 
            
            if(i<board.size()-1  && j<board[i].size()-1)
            {
                
                if(board[i+1][j+1]==1)
                {
                a++;
                }
                
            }
            
            
            if(i<board.size()-1)
            {
                
                
                
                if(board[i+1][j]==1)
                {
                    a++;
                }
                
            }
            
            
            if(j<board[i].size()-1)
            {
                 if(board[i][j+1]==1)
                {
                    a++;
                }
                
                if(board[i-1][j+1]==1)
                {
                    a++;
                }
                
                
            }
             
            
            
            
            
            
            
            
            
        }else if(j>0)
        {
            
            if(board[i][j-1]==1)
            {
                a++;
            }
            
            
            
            if(i<board.size()-1  && j<board[i].size()-1)
            {
                
                if(board[i+1][j+1]==1)
                {
                a++;
                }
                
            }
            
            
            if(i<board.size()-1)
            {
                
                if(board[i+1][j-1]==1)
                {
                    a++;
                }
                
                if(board[i+1][j]==1)
                {
                    a++;
                }
                
            }
            
            
            if(j<board[i].size()-1)
            {
                 if(board[i][j+1]==1)
                {
                    a++;
                }
                
            }
             
            
            
        }else{
            
            //here for i==0 && j==0
            
            //cout<<"i am. ere for i=0 and j=0 "<<i<<" "<<j<<endl;
            
            
            
            if(i<board.size()-1  && j<board[i].size()-1)
            {
                
                if(board[i+1][j+1]==1)
                {
                a++;
                }
                
            }
            
            
            if(i<board.size()-1)
            {
                
               
                
                if(board[i+1][j]==1)
                {
                    a++;
                }
                
            }
            
            
            if(j<board[i].size()-1)
            {
                 if(board[i][j+1]==1)
                {
                    a++;
                }
                
                
                
                
            }
             
            
        }
        
        
       
        
        return a;
        
        
        
    }
    
    
    
    
    
    void gameOfLife(vector<vector<int>>& board) {
        
        
        vector<vector<int>> board2(board);
        
        for(int i=0;i<board.size();i++)
        {
            
            for(int j=0;j<board[i].size();j++)
            {
                  int n = checklive(board,i,j);
                
                //cout<<"for "<<i<<" "<<j<<" live neighbour are "<<n<<endl;
                
                   if(n<2)
                   {
                       //cout<<"i entered here -1\n\n";
                       board2[i][j]=0;
                       
                   }else if(n==2 || n==3 )
                   {
                      // cout<<"i entered here-2\n\n";
                       if(board[i][j]==1)
                       {
                        board2[i][j]=1;   
                       }
                       
                       if(n==3 && board[i][j]==0)
                       {
                            board2[i][j]=1;   
                       }
                       
                   }else if(n>3)
                   {
                       //cout<<"i entered here-3\n\n";
                       board2[i][j]=0;
                   }
                
                
            }
            
        }
        
        
        board=board2;
            

        
    }
};
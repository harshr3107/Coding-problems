class Solution {
public:
    
    
    bool checkplace(vector<vector<char>>& board,int row,int col,int num)
    {
        
        for(int i=0;i<board[col].size();i++)
        {
            if(i!=col && board[row][i]==num)
            {
                cout<<"i entered here in 1st\n";
                return false;
            }
            
            if(i!=row && board[i][col]==num)
            {
                 //cout<<"i entered here in 2nd\n";
                return false;
            }
            
        }
        
        //cout<<"value of row is "<<row<<" value of col is "<<col<<endl;
        
        int i = (row/3)*3;
        int j= (col/3)*3;
        
       // cout<<i<<" "<<j<<endl;
        
        
        for(int k=i;k<(i+3);k++)
        {
            for(int g=j;g<(j+3);g++)
            {
                if(k!=row && g!=col && board[k][g]==num)
                {
                     //cout<<"i entered here in 3rd\n";
                    return false;
                }
                
            }
            
        }
        
        return true;
        
    }
    
    
    
    
    
    
    
    
    bool isValidSudoku(vector<vector<char>>& board) {
        
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board.size();j++)
            {
                
                if(board[i][j]!='.')
                {
                    
                    if(!checkplace(board,i,j,board[i][j]))
                    {
                        //cout<<"i entered here for "<<board[i][j]<<endl;
                        
                        return false;
                    }
                    
                    
                    
                }
                
                
                
                
            }
        }
        
        
        return true;
        
        
        
    }
};
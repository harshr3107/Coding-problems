class Solution {
public:
    
    
    bool checksafe(vector<vector<int>>& board,int row,int col,int n)
    {
        
        
        int i = row;
        int j= col;
        
        //cout<<"i am here for "<<row<<" "<<col<<endl;
        
        //check if any queen is in the same row
        
        
        while(j>=0)
        {
            if(board[i][j]==0)
            {
                return false;
            }
            
            j--;
        }
        
        
          //check in adj above
        
        j=col;
        
      
        
        while(i>=0 && j>=0)
        {
            if(board[i][j]==0)
            {
                return false;
            }
            
            i--;
            j--;
        }
        
        //check in adj below
        
        i = row;
        j= col;
        
        while(i<n && j>=0)
        {
            
            if(board[i][j]==0)
            {
                return false;
            }
            
            i++;
            j--;
            
        }
        
     
        return true;
        
    }
    
    
    
    
    
    void getallans(vector<vector<int>>& board,int n,int col,int& ans)
    {
        //cout<<" i am being called for "<<col<<endl;
        
        if(col==n)
        {
            ans+=1;
            return;
        }
        
        
        for(int row=0;row<n;row++)
        {
           
            
            if(checksafe(board,row,col,n))
            {
                //cout<<"safe for "<<row<<" "<<col<<endl;
                board[row][col]=0;
                getallans(board,n,col+1,ans);
                board[row][col]=-1;
                    
            }
            
        }
        
    }
    
    
    
    
    
    int totalNQueens(int n) {
        
        int ans=0;
        
        int row=0;
        int col=0;
        
        vector<vector<int>> board(n,vector<int>(n,-1));
        
        
        
        getallans(board,n,row,ans);
        
        return ans;
        
    }
};
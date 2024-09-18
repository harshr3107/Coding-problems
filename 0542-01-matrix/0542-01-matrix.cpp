class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        
        vector<vector<int>> ans(mat);
        
        vector<vector<bool>> visited;
        
        
        
        
        queue<pair<pair<int,int>,int>> q;
        
        
         
        
         for(int i=0;i<mat.size();i++)
         {
             vector<bool> v(mat[i].size(),false);
             visited.push_back(v);
             
             for(int j=0;j<mat[i].size();j++)
             {
                 if(mat[i][j]==0)
                 {
                     q.push(make_pair(make_pair(i,j),0));
                     visited[i][j]=true;
                 }
             }
             
         }
        
        
        while(!q.empty())
        {
          
            pair<pair<int,int>,int> temp = q.front();
            q.pop();
            int row = temp.first.first;
            int col =  temp.first.second;
            int curt = temp.second;
            
            
            if((row-1)>=0)
            {
                if(mat[row-1][col]==1 && visited[row-1][col]==false)
                {
                    ans[row-1][col]=curt+1;
                    visited[row-1][col]=true;
                    q.push(make_pair(make_pair(row-1,col),curt+1));
                    
                }
                
            }
            
            if((row+1)<mat.size())
            {
                
                 if(mat[row+1][col]==1 && visited[row+1][col]==false)
                {
                    ans[row+1][col]=curt+1;
                    visited[row+1][col]=true;
                    q.push(make_pair(make_pair(row+1,col),curt+1));
                    
                }
                
            }
            
            if((col-1)>=0)
            {
                
                 if(mat[row][col-1]==1 && visited[row][col-1]==false)
                {
                    ans[row][col-1]=curt+1;
                    visited[row][col-1]=true;
                    q.push(make_pair(make_pair(row,col-1),curt+1));
                    
                }
                
            }
            
            if((col+1)<mat[row].size())
            {
                 if(mat[row][col+1]==1 && visited[row][col+1]==false)
                {
                    ans[row][col+1]=curt+1;
                    visited[row][col+1]=true;
                    q.push(make_pair(make_pair(row,col+1),curt+1));
                    
                }
                
            }
            
            
            
            
            
            
            
            
    }
        
        
         /*for(int i=0;i<mat.size();i++)
         {
             
             
             for(int j=0;j<mat[i].size();j++)
             {
                 cout<<visited[i][j]<<" ";
             }
             
             cout<<endl;
             
         }
        
        
        */
        
        
        
        return ans;
        
        
    }
};
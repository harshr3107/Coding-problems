class Solution {
public:
    
    
    
    void getbfs(vector<vector<int>>& land,int cr,int cc,vector<vector<bool>>& visited,vector<int>& v)
    {
        
        visited[cr][cc]=true;
        
        int a=cr;
        int b=cc;
        
        queue<pair<int,int>> q;
        q.push(make_pair(cr,cc));
        
        
        while(!q.empty())
        {
            
            pair<int,int> temp = q.front();
            q.pop();
            int row = temp.first;
            int col = temp.second;
            a=row;
            b=col;
            
            
            if((row-1)>=0 && land[row-1][col]==1 && visited[row-1][col]==false)
            {
                visited[row-1][col]=true;
                q.push(make_pair(row-1,col));
                
            }
            
            if((row+1)<land.size() && land[row+1][col]==1 && visited[row+1][col]==false)
            {
                visited[row+1][col]=true;
                q.push(make_pair(row+1,col));
                
            }
            
            if((col-1)>=0 && land[row][col-1]==1 && visited[row][col-1]==false)
            {
                visited[row][col-1]=true;
                q.push(make_pair(row,col-1));
                
            }
            
            if((col+1)<land[row].size() && land[row][col+1]==1 && visited[row][col+1]==false)
            {
                visited[row][col+1]=true;
                q.push(make_pair(row,col+1));
                
            }
            
            
            
            
            
            
        }
        
        cout<<"val of a and b here is "<<a<<" "<<b<<endl;
        
     
        v.push_back(a);
        v.push_back(b);        
        
    }
    
    
    
    
    
    
    
    
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        
        
        vector<vector<bool>> visited;
        
        for(int i=0;i<land.size();i++)
        {
           vector<bool> v(land[i].size(),false);
           visited.push_back(v); 
            
        }
        
        
        vector<vector<int>> ans;
        
        for(int i=0;i<land.size();i++)
        {
            for(int j=0;j<land[i].size();j++)
            {
                if(land[i][j]==1 && visited[i][j]==false)
                {
                    vector<int> v;
                    v.push_back(i);
                    v.push_back(j);
                    getbfs(land,i,j,visited,v);
                    ans.push_back(v);
                    
                }
                
            }
            
        }
        
        
        
        return ans;
        
        
        
    }
};
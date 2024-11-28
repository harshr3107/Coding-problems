class Solution {
public:
    
    
    
    int minimumObstacles(vector<vector<int>>& grid) {
        
       set<pair<int,pair<int,int>>> s;
        
        s.insert(make_pair(0,make_pair(0,0)));
        vector<vector<bool>> visited(grid.size(),vector<bool>(grid[0].size(),false));
        vector<vector<int>> obs(grid.size(),vector<int>(grid[0].size(),INT_MAX));
        
        
        int m = grid.size();
        int n = grid[0].size();
        
        obs[0][0]=1;
        
        while(!s.empty())
        {
            
            pair<int,pair<int,int>> temp = *s.begin();
            int obstacle = temp.first;
            int i = temp.second.first;
            int j = temp.second.second;
            s.erase(s.begin());
            
            
            if(i==m-1 && j==n-1)
            {
              
                return obstacle;
            }
            
        
            if((i+1)<m && visited[i+1][j]==false)
            {
                  if(obstacle+grid[i+1][j]<obs[i+1][j])
                  {
                      if(s.count(make_pair(obs[i+1][j],make_pair(i+1,j))))
                      {
                          s.erase(make_pair(obs[i+1][j],make_pair(i+1,j)));
                      }
                      
                      int newdis = obstacle+grid[i+1][j];
                      s.insert(make_pair(newdis,make_pair(i+1,j)));
                      obs[i+1][j]=newdis;
                      
                      
                  }
                
                
            }
            
            
            if((i-1)>=0 && visited[i-1][j]==false)
            {
                
                 if(obstacle+grid[i-1][j]<obs[i-1][j])
                  {
                      if(s.count(make_pair(obs[i-1][j],make_pair(i-1,j))))
                      {
                          s.erase(make_pair(obs[i-1][j],make_pair(i-1,j)));
                      }
                      
                      int newdis = obstacle+grid[i-1][j];
                      s.insert(make_pair(newdis,make_pair(i-1,j)));
                      obs[i-1][j]=newdis;
                      
                      
                  }
                
            }

            if((j+1)<n && visited[i][j+1]==false)
            {
                
                 if(obstacle+grid[i][j+1]<obs[i][j+1])
                  {
                      if(s.count(make_pair(obs[i][j+1],make_pair(i,j+1))))
                      {
                          s.erase(make_pair(obs[i][j+1],make_pair(i,j+1)));
                      }
                      
                      int newdis = obstacle+grid[i][j+1];
                      s.insert(make_pair(newdis,make_pair(i,j+1)));
                      obs[i][j+1]=newdis;
                      
                      
                  }
                
                
            }
            
            if((j-1)>=0 && visited[i][j-1]==false)
            {
                
                if(obstacle+grid[i][j-1]<obs[i][j-1])
                  {
                      if(s.count(make_pair(obs[i][j-1],make_pair(i,j-1))))
                      {
                          s.erase(make_pair(obs[i][j-1],make_pair(i,j-1)));
                      }
                      
                      int newdis = obstacle+grid[i][j-1];
                      s.insert(make_pair(newdis,make_pair(i,j-1)));
                      obs[i][j-1]=newdis;
                      
                      
                  }
                
                
            }
            
        }
        
        
        
     return -1;   
        
    }
};
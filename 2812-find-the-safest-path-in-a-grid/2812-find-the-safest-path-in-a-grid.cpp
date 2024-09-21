class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        
        
        vector<vector<int>> dis;
        
       
        
        vector<vector<int>> hdis;
        
        
        for(int i=0;i<grid.size();i++)
        {
            vector<int> v(grid[i].size(),INT_MAX);
            vector<int> v3(grid[i].size(),INT_MIN);
            
            dis.push_back(v);
            hdis.push_back(v3);
            
        }
        
        
        queue<pair<int,pair<int,int>>> q;
        
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[i].size();j++)
            {
                if(grid[i][j]==1)
                {
                    
                    q.push(make_pair(0,make_pair(i,j)));
                    dis[i][j]=0;
                    
                }
            }
            
        }
      
        
        
        while(!q.empty())
        {
            pair<int,pair<int,int>> p = q.front();
            q.pop();
            
            int dist = p.first;
            int row = p.second.first;
            int col = p.second.second;
            
            
            
            
            if((row-1)>=0 && dis[row-1][col]==INT_MAX)
            {
                dis[row-1][col]=dist+1;
                q.push(make_pair(dist+1,make_pair(row-1,col)));
                
            }
            
            
            if((row+1)<grid.size() && dis[row+1][col]==INT_MAX)
            {
                dis[row+1][col]=dist+1;
                q.push(make_pair(dist+1,make_pair(row+1,col)));
                
            }
            
             if((col-1)>=0 && dis[row][col-1]==INT_MAX)
            {
                dis[row][col-1]=dist+1;
                q.push(make_pair(dist+1,make_pair(row,col-1)));
                
            }
            
            
             if((col+1)<grid[row].size() && dis[row][col+1]==INT_MAX)
            {
                dis[row][col+1]=dist+1;
                q.push(make_pair(dist+1,make_pair(row,col+1)));
                
            }
            
            
        }
        
        
        
       /* for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[i].size();j++)
            {
                cout<<dis[i][j]<<" ";
            }
            
            cout<<endl;
            
        }
        */
        
        //cout<<endl<<endl;
        
        
        set<pair<int,pair<int,int>>> s;
        hdis[0][0]=dis[0][0];
        
        s.insert(make_pair(hdis[0][0],make_pair(0,0)));
        
        
        while(!s.empty())
        {
            
            pair<int,pair<int,int>> temp =  *(s.rbegin());
            s.erase(*(s.rbegin()));
            int d = temp.first;
            int row = temp.second.first;
            int col = temp.second.second;
            
           
            
            
            
            if((row-1)>=0)
            {
                
                //
                int a = min(d,dis[row-1][col]);
                
                if(a>hdis[row-1][col])
                {
                    
                     
                    /*if(s.count(make_pair(hdis[row-1][col],make_pair(row-1,col))))
                    {
                        s.erase(s.find(make_pair(hdis[row-1][col],make_pair(row-1,col))));
                    }*/
                    
                    
                    
                   hdis[row-1][col]=a;
                    
                    s.insert(make_pair(a,make_pair(row-1,col)));
                }
    
            }
            
          
            
            if((row+1)<grid.size())
            {
                
                int a = min(d,dis[row+1][col]);
                
                if(a>hdis[row+1][col])
                {
                    
                    
                   /* if(s.count(make_pair(hdis[row+1][col],make_pair(row+1,col))))
                    {
                        s.erase(s.find(make_pair(hdis[row+1][col],make_pair(row+1,col))));
                    }*/
                    
                    
                    
                    hdis[row+1][col]=a;
                    
                    s.insert(make_pair(a,make_pair(row+1,col)));
                }
                
                
                
            }
            
            
            if(col-1>=0)
            {
                int a = min(d,dis[row][col-1]);
                
                if(a>hdis[row][col-1])
                {
                    
                    
                   /* if(s.count(make_pair(hdis[row][col-1],make_pair(row,col-1))))
                    {
                        s.erase(s.find(make_pair(hdis[row][col-1],make_pair(row,col-1))));
                    }*/
                    
                    
                    
                    hdis[row][col-1]=a;
                    
                    s.insert(make_pair(a,make_pair(row,col-1)));
                }
                
                
            }
            
            
            if(col+1<grid[row].size())
            {
                int a = min(d,dis[row][col+1]);
                
                if(a>hdis[row][col+1])
                {
                    
                   /* if(s.count(make_pair(hdis[row][col+1],make_pair(row,col+1))))
                    {
                        s.erase(s.find(make_pair(hdis[row][col+1],make_pair(row,col+1))));
                    }
                    */
                    
                    
                    hdis[row][col+1]=a;
                    
                   
                    
                    s.insert(make_pair(a,make_pair(row,col+1)));
                }
                
            }
            
            
            
            
            
            
            
        }
        
        
        
        
       /* for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[i].size();j++)
            {
                cout<<hdis[i][j]<<" ";
            }
            
            cout<<endl;
            
        }*/
      
        
        
        //cout<<endl;
        
        
        return hdis[grid.size()-1][grid[0].size()-1];
      
        
      
        
        
        
        
        
        
        
        
    }
};
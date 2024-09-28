


class disjoint_set
{
    public:
    
    vector<int> parent;
    vector<int> size;
    
    
    disjoint_set(int n)
    {
        for(int i=0;i<n;i++)
        {
            parent.push_back(i);
            size.push_back(1);
        }
    }
    
    
    int getparent(int u)
    {
        if(parent[u]==u)
        {
            return u;
        }
        
        parent[u]=getparent(parent[u]);
        
        return parent[u];
        
    }
    
    
    void unionbysize(int u,int v)
    {
        int ulp_u = getparent(u);
        int ulp_v = getparent(v);
        
        if(ulp_u==ulp_v)
        {
            return;
        }
        
        if(size[ulp_u]>size[ulp_v])
        {
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }else{
            
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
            
        }
        
    }
    
    
  
    
    
    
    
};









class Solution {
public:
    
    
    

    
    
    int largestIsland(vector<vector<int>>& grid) {
        
        
        int n = grid.size();
        int m = grid[0].size();
        
        int tnodes = m*n;
        
        
        
        disjoint_set* ds = new disjoint_set(tnodes);
        
       
        
        
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[i].size();j++)
            {
                
               
                 if(grid[i][j]==1)
                 {
                  
                    int row = i;
                    int col= j;
                    int u1 = (row*m)+col;
                
                   
                
                    if((row-1)>=0 && grid[row-1][col]==1)
                    {
                        
                        int u2 = ((row-1)*m)+col;
                        
                       
                            ds->unionbysize(u1,u2);
                        
                        
                    }
                    
                    if((row+1)<n && grid[row+1][col]==1)
                    {
                      
                        int u2 = ((row+1)*m)+col;
                        
                        
                            ds->unionbysize(u1,u2);
                        
                        
                    }
                    
                    if((col-1)>=0 && grid[row][col-1]==1)
                    {
                       
                        int u2 = (row*m)+(col-1);
                        
                        
                            ds->unionbysize(u1,u2);
                        
                        
                    }
                    
                     if((col+1)<m && grid[row][col+1]==1)
                    {
                       
                        int u2 = (row*m)+(col+1);
                        
                        
                            ds->unionbysize(u1,u2);
                        
                        
                    }
                    
                    
                    
                    
                
                 }
                
            }
            
            
        }
        
       
            
        
        int ans= *max_element(ds->size.begin(),ds->size.end());
        
        
        
           for(int i=0;i<grid.size();i++)
          {
            for(int j=0;j<grid[i].size();j++)
            {
                
               
                 if(grid[i][j]==0)
                 {
                  
                    int row = i;
                    int col= j;
                    set<int> parents;
                
                   
                
                    if((row-1)>=0 && grid[row-1][col]==1)
                    {
                        
                        parents.insert(ds->getparent(((row-1)*m)+col));
                        
                        
                    }
                    
                    if((row+1)<n && grid[row+1][col]==1)
                    {
                      
                       parents.insert(ds->getparent(((row+1)*m)+col));
                        
                        
                    }
                    
                    if((col-1)>=0 && grid[row][col-1]==1)
                    {
                       
                        parents.insert(ds->getparent((row*m)+col-1));
                        
                        
                    }
                    
                     if((col+1)<m && grid[row][col+1]==1)
                    {
                       
                         parents.insert(ds->getparent((row*m)+col+1));
                        
                        
                    }
                     
                    
                     int newsize=1;
                     for(auto it : parents)
                     {
                         newsize+=ds->size[it];
                     }
                    
                    ans = max(ans,newsize);
                    
                
                 }
                
            }
            
            
        }
        
        
        
        
        
        
        
        
        
        
        
        
        //cout<<"here the ans is "<<ans<<endl;
        
        
       /* for(auto it : s)
        {
            int row = it.first;
            int col = it.second;
          
            
            //cout<<"i am checking for "<<row<<" "<<col<<endl;
            
            vector<int> siz1 = ds->size;
            vector<int> par1 = ds->parent;
            
            
             
                    if((row-1)>=0 && grid[row-1][col]==1)
                    {
                       
                        int u1 = (row*m)+col;
                        int u2 = ((row-1)*m)+col;
                        
                        
                            ds->unionbysize(u1,u2);
                        
                        
                    }
                    
                    if((row+1)<n && grid[row+1][col]==1)
                    {
                        int u1 = (row*m)+col;
                        int u2 = ((row+1)*m)+col;
                        
                       
                            ds->unionbysize(u1,u2);
                        
                        
                    }
                    
                    if((col-1)>=0 && grid[row][col-1]==1)
                    {
                        //cout<<"i entered here\n";
                        int u1 = (row*m)+col;
                        int u2 = (row*m)+(col-1);
                        
                       
                            ds->unionbysize(u1,u2);
                        
                        
                    }
                    
                     if((col+1)<m && grid[row][col+1]==1)
                    {
                        int u1 = (row*m)+col;
                        int u2 = (row*m)+(col+1);
                        
                       
                            ds->unionbysize(u1,u2);
                        
                        
                    }
            
            
             ans = max(ans,*max_element(ds->size.begin(),ds->size.end()));
            
            ds->size = siz1;
            ds->parent = par1;
            
            
        }
        */
        
        
        
        
        
        return ans;
        
        
        
        
        
        
    }
};
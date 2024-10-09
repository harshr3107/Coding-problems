class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        
        int i=0;
        int j=0;
        
        queue<pair<int,int>> q;
        
        set<pair<int,int>> s;
        
        
        for(int i=0;i<grid.size();i++)
        {
            int a=0;
            
            for(int j=0;j<grid[i].size();j++)
            {
                if(grid[i][j]==1)
                {
                    a++;
                    cout<<"i am herer for "<<i<<" "<<j<<endl;
                    q.push(make_pair(i,j));
                    s.insert(make_pair(i,j));
                    break;
                }
            }
            
            if(a!=0)
            {
                break;
            }
        }
        
        
        int ans=0;
        
       
        while(!q.empty())
        {
        
            
            pair<int,int> temp = q.front();
            q.pop();
            
            int i = temp.first;
            int j = temp.second;
            
            cout<<"i entered here for "<<i<<" and "<<j<<" and cur val of ans is "<<ans<<endl;
            
            
            if((i-1)>=0 && grid[i-1][j]==1 && s.count(make_pair(i-1,j))==0)
            {
                s.insert(make_pair(i-1,j));
                q.push(make_pair(i-1,j));
                
            }else if(i==0 || grid[i-1][j]==0)
            {
                ans++;
            }
            
            if((i+1)<grid.size() && grid[i+1][j]==1 && s.count(make_pair(i+1,j))==0)
            {
                s.insert(make_pair(i+1,j));
                q.push(make_pair(i+1,j));
                
            }else if(i==grid.size()-1 || grid[i+1][j]==0){
                ans++;
            }
            
            
            if((j-1)>=0 && grid[i][j-1]==1 && s.count(make_pair(i,j-1))==0)
            {
                  s.insert(make_pair(i,j-1));
                  q.push(make_pair(i,j-1));
                
            }else if(j==0 || grid[i][j-1]==0){
               
                ans++;
            }
            
            if((j+1)<grid[i].size() && grid[i][j+1]==1 && s.count(make_pair(i,j+1))==0)
            {
                  s.insert(make_pair(i,j+1));
                  q.push(make_pair(i,j+1));
            }else if(j==grid[i].size()-1 || grid[i][j+1]==0){
               
                ans++;
            }
            
            
            
            
        }
        
        return ans;
        
        
    }
};
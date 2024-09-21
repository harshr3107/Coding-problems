/*class Solution {
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
        
        
      
        
      
        
        
        //we need a path which has minimum maximum distANCE FROM o,o to n-1,n-1
        
        hdis[0][0]=dis[0][0];
        set<pair<int,pair<int,int>>> s;
        
        s.insert(make_pair(hdis[0][0],make_pair(0,0)));
        
        
        while(!s.empty())
        {
            
            pair<int,pair<int,int>> temp = *(s.begin());
            s.erase(s.begin());
            
            int d = temp.first;
            int row = temp.second.first;
            int col = temp.second.second;
            
           // visited[row][col]=true;
            
            
            if((row-1)>=0  &&  (hdis[row-1][col]<min(d,dis[row-1][col])))
            {
                
                hdis[row-1][col]=min(d,dis[row-1][col]);
                s.insert(make_pair(hdis[row-1][col],make_pair(row-1,col)));
                 
                
            }
            
            
            if((row+1)<grid.size() && (hdis[row+1][col]<min(d,dis[row+1][col])))
            {
               int a = min(d,dis[row+1][col]);
               hdis[row+1][col]=a;
               s.insert(make_pair(a,make_pair(row+1,col)));
                
            }
            
            
            if((col-1)>=0 && (hdis[row][col-1]<min(d,dis[row][col-1])) )
            {
                
              int a = min(d,dis[row][col-1]);
              hdis[row][col-1]=a;
              s.insert(make_pair(a,make_pair(row,col-1)));
            }
            
            
            if((col+1)<grid[row].size() && (hdis[row][col+1]<min(d,dis[row][col+1])))
            {
                int a = min(d,dis[row][col+1]);
                hdis[row][col+1]=a;
                s.insert(make_pair(a,make_pair(row,col+1)));
                
            }
            
    }
        
       
      
        
        
        cout<<endl;
        
        
        
        
        
        
        return hdis[grid.size()-1][grid[0].size()-1];
        
        
        
        
        
        
        
        
    }
};*/


class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dis(n, vector<int>(n, INT_MAX));
        vector<vector<int>> hdis(n, vector<int>(n, INT_MIN));
        
        // BFS to calculate distance from thieves (1s in the grid)
        queue<pair<int, pair<int, int>>> q;
        
        // Start from all thief positions
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    q.push({0, {i, j}});
                    dis[i][j] = 0;
                }
            }
        }
        
        // BFS to compute the distance from the nearest thief
        vector<int> dirs = {-1, 0, 1, 0, -1};
        while (!q.empty()) {
            auto [dist, pos] = q.front();
            int row = pos.first, col = pos.second;
            q.pop();
            
            for (int d = 0; d < 4; ++d) {
                int r = row + dirs[d], c = col + dirs[d+1];
                if (r >= 0 && r < n && c >= 0 && c < n && dis[r][c] == INT_MAX) {
                    dis[r][c] = dist + 1;
                    q.push({dist + 1, {r, c}});
                }
            }
        }
        
        // Dijkstra-like approach to find path with maximum minimum safeness factor
        priority_queue<pair<int, pair<int, int>>> pq;
        hdis[0][0] = dis[0][0];
        pq.push({hdis[0][0], {0, 0}});
        
        while (!pq.empty()) {
            auto [d, pos] = pq.top();
            int row = pos.first, col = pos.second;
            pq.pop();
            
            if (row == n - 1 && col == n - 1) {
                return d;  // Found the safest path to the bottom-right corner
            }
            
            for (int dir = 0; dir < 4; ++dir) {
                int r = row + dirs[dir], c = col + dirs[dir + 1];
                if (r >= 0 && r < n && c >= 0 && c < n) {
                    int newSafeness = min(d, dis[r][c]);
                    if (newSafeness > hdis[r][c]) {
                        hdis[r][c] = newSafeness;
                        pq.push({newSafeness, {r, c}});
                    }
                }
            }
        }
        
        return hdis[n - 1][n - 1];  // Fallback, should always return in the loop
    }
};

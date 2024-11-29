/*class Solution {
public:
    
    
    
    
    
    
    
    int minimumTime(vector<vector<int>>& grid) {
        
        set<pair<int,pair<int,int>>> s;
        
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> time(n,vector<int>(m,INT_MAX));
        
        time[0][0]=0;
        s.insert(make_pair(1,make_pair(0,0)));
        
        
        while(!s.empty())
        {
            
            
            pair<int,pair<int,int>> temp = *s.begin();
            int ctime = temp.first;
            int i = temp.second.first;
            int j = temp.second.second;
            
            //cout<<i<<" "<<j<<" "<<ctime<<endl;
            
            s.erase(s.begin());
            
            
            
            if(i==n-1 && j==m-1)
            {
                return ctime-1;
            }
            
            
            
            if((i+1)<n)
            {
                if(grid[i+1][j]<=ctime)
                {
                 
                        pair<int,pair<int,int>> tempo = make_pair(time[i+1][j],make_pair(i+1,j));
                        
                        if(s.count(tempo))
                        {
                            s.erase(tempo);
                        }
                        
                        
                        time[i+1][j]=ctime+1;
                        s.insert(make_pair(time[i+1][j],make_pair(i+1,j)));
                    
                }
                
            }
            
            
            if((i-1)>=0)
            {
                
                if(grid[i-1][j]<=ctime)
                {
                
                        pair<int,pair<int,int>> tempo = make_pair(time[i-1][j],make_pair(i-1,j));
                        
                        if(s.count(tempo))
                        {
                            s.erase(tempo);
                        }
                        
                        
                        time[i-1][j]=ctime+1;
                        s.insert(make_pair(time[i-1][j],make_pair(i-1,j)));
                    
                }
                    
                }
                
                
                
                
            
            
            
            if((j+1)<m)
            {
                
                
                if(grid[i][j+1]<=ctime)
                {
                
                        pair<int,pair<int,int>> tempo = make_pair(time[i][j+1],make_pair(i,j+1));
                        
                        if(s.count(tempo))
                        {
                            s.erase(tempo);
                        }
                        
                        
                        time[i][j+1]=ctime+1;
                        s.insert(make_pair(time[i][j+1],make_pair(i,j+1)));
                    
                
                }
                
                
            }
           
            if((j-1)>=0)
            {
                
                
                
                if(grid[i][j-1]<=ctime)
                {
                
                        pair<int,pair<int,int>> tempo = make_pair(time[i][j-1],make_pair(i,j-1));
                        
                        if(s.count(tempo))
                        {
                            s.erase(tempo);
                        }
                        
                        
                        time[i][j-1]=ctime+1;
                        s.insert(make_pair(time[i][j-1],make_pair(i,j-1)));
                    
                
                
                
                }
            }
        }
            
            
            
            
            
            
        
        
        
        return -1;
        
        
        
    }
};*/


class Solution {
public:
    typedef pair<int,pair<int,int>> p;
    
    int minimumTime(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        //case when no moves can be made [can't reach the destination]
        if(grid[0][1]>1 && grid[1][0]>1)   return -1;
        
        //helping matrices
        vector<vector<int>> time(n, vector<int> (m,INT_MAX));
        vector<int> drow {0,-1,0,1};
        vector<int> dcol {-1,0,1,0};
        
        //minHeap for dijkstra's
        priority_queue<p,vector<p>,greater<p>> q;
        //pushing initial values of source
        q.push({0,{0,0}});
        time[0][0] = 0;
        int res = INT_MAX;
        
        while(!q.empty())   {
            auto it = q.top();
            q.pop();
            int r = it.second.first;
            int c = it.second.second;
            int t = it.first;
            
            //case when destination is reached (possible answer)
            if(r==n-1 && c==m-1)    
                res = min(res,t);
            
            //incrementing time for the next new moves
            t++;
            
            //checking all four directions
            for(int i=0; i<4; i++)  {
                int dr = r+drow[i];
                int dc = c+dcol[i];
                
                if(dr>=0&&dr<n&&dc>=0&&dc<m) {
                    if(time[dr][dc]==INT_MAX)   {
                        //case 1
                        if(grid[dr][dc]<=t) {
                            time[dr][dc] = t;
                            q.push({t,{dr,dc}});
                        }
                        //case 2
                        else {
                            int dif = grid[dr][dc]-t;
                            if(dif%2==0)    {
                                time[dr][dc] = grid[dr][dc];
                                q.push({grid[dr][dc],{dr,dc}});
                            }
                            else {
                                time[dr][dc] = grid[dr][dc]+1;
                                q.push({grid[dr][dc]+1,{dr,dc}});
                            }
                        }
                    }
                    else {
                        if(time[dr][dc]>t)  {
                            //case 3.a
                            if(grid[dr][dc]<=t)  {
                                time[dr][dc] = t;
                                q.push({t,{dr,dc}});                                
                            }
                            //case 3.b
                            else {
                                int dif = grid[dr][dc]-t;
                                if(dif%2==0)    {
                                    time[dr][dc] = grid[dr][dc];
                                    q.push({grid[dr][dc],{dr,dc}});
                                }
                                else {
                                    time[dr][dc] = grid[dr][dc]+1;
                                    q.push({grid[dr][dc]+1,{dr,dc}});
                                }
                            }
                        }
                    }
                }
            }
        }
        
        if(res==INT_MAX)
            return -1;
        return res;
    }
};


/*
class Solution {
public:
    
    
    
    
    
    
    
    int minimumTime(vector<vector<int>>& grid) {
        
        set<pair<int,pair<int,int>>> s;
        
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> time(n,vector<int>(m,INT_MAX));
        
        time[0][0]=0;
        s.insert(make_pair(0,make_pair(0,0)));
        
        
        while(!s.empty())
        {
            
            
            pair<int,pair<int,int>> temp = *s.begin();
            int ctime = temp.first;
            int i = temp.second.first;
            int j = temp.second.second;
            
            s.erase(s.begin());
            
            
            
            if(i==n-1 && j==m-1)
            {
                return ctime;
            }
            
            
            
            //Down
            if((i+1)<n)
            {
                if((ctime)>=grid[i+1][j])
                {
                    if(time[i+1][j]>(ctime+1))
                    {
                        if(s.count(make_pair(time[i+1][j],make_pair(i+1,j))))
                        {
                            s.erase(make_pair(time[i+1][j],make_pair(i+1,j)));
                        }
                        
                        time[i+1][j]=ctime+1;
                        s.insert(make_pair(ctime+1,make_pair(i+1,j)));
                        
                    }
                    
                }else{
                    
                    
                   int reqtime = max(ctime, grid[i+1][j]) + 1;
                    
                    if(time[i+1][j]>reqtime)
                    {
                        
                        if(s.count(make_pair(time[i+1][j],make_pair(i+1,j))))
                        {
                            s.erase(make_pair(time[i+1][j],make_pair(i+1,j)));
                        }
                        
                        time[i+1][j]=reqtime;
                        s.insert(make_pair(reqtime,make_pair(i+1,j)));
                        
                        
                    }
                    
                    
                }
                
                
            }
            
            
            //Up
            if((i-1)>=0)
            {
                
                if((ctime)>=grid[i-1][j])
                {
                    if(time[i-1][j]>(ctime+1))
                    {
                        if(s.count(make_pair(time[i-1][j],make_pair(i-1,j))))
                        {
                            s.erase(make_pair(time[i-1][j],make_pair(i-1,j)));
                        }
                        
                        time[i-1][j]=ctime+1;
                        s.insert(make_pair(ctime+1,make_pair(i-1,j)));
                        
                    }
                    
                }else{
                    
                    
                   int reqtime = max(ctime, grid[i-1][j]) + 1;
                    
                    if(time[i-1][j]>reqtime)
                    {
                        
                        if(s.count(make_pair(time[i-1][j],make_pair(i-1,j))))
                        {
                            s.erase(make_pair(time[i-1][j],make_pair(i-1,j)));
                        }
                        
                        time[i-1][j]=reqtime;
                        s.insert(make_pair(reqtime,make_pair(i-1,j)));
                        
                        
                    }
                    
                    
                }
                
                
            }
            
            //Right
            if((j+1)<m)
            {
                
                if((ctime)>=grid[i][j+1])
                {
                    if(time[i][j+1]>(ctime+1))
                    {
                        if(s.count(make_pair(time[i][j+1],make_pair(i,j+1))))
                        {
                            s.erase(make_pair(time[i][j+1],make_pair(i,j+1)));
                        }
                        
                        time[i][j+1]=ctime+1;
                        s.insert(make_pair(ctime+1,make_pair(i,j+1)));
                        
                    }
                    
                }else{
                    
                    
                    int reqtime = max(ctime, grid[i][j+1]) + 1;
                    
                    if(time[i][j+1]>reqtime)
                    {
                        
                        if(s.count(make_pair(time[i][j+1],make_pair(i,j+1))))
                        {
                            s.erase(make_pair(time[i][j+1],make_pair(i,j+1)));
                        }
                        
                        time[i][j+1]=reqtime;
                        s.insert(make_pair(reqtime,make_pair(i,j+1)));
                        
                        
                    }
                    
                    
                }
                
                
            }
            
            //Left
            if((j-1)>=0)
            {
                
                
                if((ctime)>=grid[i][j-1])
                {
                    if(time[i][j-1]>(ctime+1))
                    {
                        if(s.count(make_pair(time[i][j-1],make_pair(i,j-1))))
                        {
                            s.erase(make_pair(time[i][j-1],make_pair(i,j-1)));
                        }
                        
                        time[i][j-1]=ctime+1;
                        s.insert(make_pair(ctime+1,make_pair(i,j-1)));
                        
                    }
                    
                }else{
                    
                    
                    int reqtime = max(ctime, grid[i][j-1]) + 1;
                    
                    if(time[i][j-1]>reqtime)
                    {
                        
                        if(s.count(make_pair(time[i][j-1],make_pair(i,j-1))))
                        {
                            s.erase(make_pair(time[i][j-1],make_pair(i,j-1)));
                        }
                        
                        time[i][j-1]=reqtime;
                        s.insert(make_pair(reqtime,make_pair(i,j-1)));
                        
                        
                    }
                    
                    
                }
                
                
                
            }
            
            
            
            
            
            
        }
        
        
        return 0;
        
        
        
    }
};
*/
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        //create a graph first
        
        vector<vector<pair<int,int>>> adj(n);
        
        for(int i=0;i<flights.size();i++)
        {
            int u = flights[i][0];
            int v = flights[i][1];
            int w = flights[i][2];
            
            
            adj[u].push_back(make_pair(v,w));
            
        }
        
        
        
        vector<int> price(n+1,INT_MAX);
        price[src]=0;
        
        queue<pair<int,pair<int,int>>> q;
        q.push(make_pair(src,make_pair(-1,0)));
        
        
        set<int> s;
        
        
        while(!q.empty())
        {
            int current = q.front().first;
            int prices =q.front().second.second;
            int stops = q.front().second.first;
            q.pop();
            
            //cout<<current<<" "<<price<<" "<<stops<<endl;
            
            
            if(stops>k)
            {
                continue;
            }
            
           
            if(current==dst && stops<=k)
            {
                //cout<<"i am entering here at price "<<price<<endl;
                //ans.push_back(price);
                s.insert(prices);
            }
            
            //cout<<adj[current].size()<<endl;
            
            for(int i=0;i<adj[current].size();i++)
            {
                //cout<<"yaha aayyyaa mai\n";
                if(price[adj[current][i].first]>adj[current][i].second+prices)
                {
                    price[adj[current][i].first]=adj[current][i].second+prices;
                    q.push(make_pair(adj[current][i].first,make_pair(stops+1,adj[current][i].second+prices)));
                }
                
            }
           
        }
        
        
        if(s.empty())
        {
            return -1;
        }
        
        return *s.begin();
        
        
        
        
         
        
        
    }
};
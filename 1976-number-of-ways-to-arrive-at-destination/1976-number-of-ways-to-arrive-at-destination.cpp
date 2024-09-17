class Solution {
public:
    
    
    
    
    
    
    
    
    
    int countPaths(int n, vector<vector<int>>& roads) {
        
        //form the graph
        
        vector<vector<pair<long long,long long>>> adj(n);
        
        for(int i=0;i<roads.size();i++)
        {
            int u = roads[i][0];
            int v = roads[i][1];
            int t = roads[i][2];
            
            adj[u].push_back(make_pair(v,t));
            adj[v].push_back(make_pair(u,t));
            
        }
        //now this is a bidirectional graph with all weight positive the method would be using tropological sort
        
       //priority_queue<pair<long,long>,vector<pair<long,long>>,greater<pair<long,long>>> minheap;
        
        set<pair<long long,long long>> s;
        
        //time to reach,node
        
        s.insert(make_pair(0,0));
        vector<long long> time(n,LONG_MAX);
        vector<long long> ways(n,0);
        time[0]=0;
        ways[0]=1;
        
        long  mod = 1e9+7;
        
        while(!s.empty())
        {
            //cout<<"mai yaja jhoon\n";
            
            long long  timereq = (*s.begin()).first;
            long long  current = (*s.begin()).second;
            
            //cout<<timereq<<" "<<current<<endl;
            
             //cout<<s.size()<<endl;
            s.erase(s.begin());
            
            //cout<<s.size()<<endl;
            
            
            for(int i=0;i<adj[current].size();i++)
            {
                long  timechild = adj[current][i].second;
                long nodechild = adj[current][i].first;
                    
                
                
                if(timereq+timechild==time[nodechild])
                {
                    ways[nodechild]=(ways[nodechild]+ways[current])%mod;
                    
                }else if((timereq+timechild)<time[nodechild])
                {
                    if(s.count(make_pair(time[nodechild],nodechild)))
                    {
                      s.erase(s.find(make_pair(time[nodechild],nodechild)));
                    }
                    
                    time[nodechild]=timereq+timechild;
                    ways[nodechild]=ways[current];
                    
                    
                    
                    s.insert(make_pair(time[adj[current][i].first],adj[current][i].first));
                }
                
                
            }
            
            
            
            
            
            
        }
        
        
     
        
        return ways[n-1]%mod;
        
        
        
        
        
        
    }
};

/*

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        int M=1e9+7;
        if(n==2)
            return 1;
        if(n==1)
            return 1;
        unordered_map<long long,list<pair<long long,long long>>> adj;
        for(int i=0;i<roads.size();i++)
        {
            long long u=roads[i][0];
            long long v=roads[i][1];
            long long w=roads[i][2];
            
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        
        set<pair<long long,long long>> st;
        vector<long long> distance(n,LONG_MAX);
        vector<long long> path(n,0);
        distance[0]=0;
        path[0]=1;
        
        st.insert({0,0});
        
        while(!st.empty())
        {
            auto top=*(st.begin());
            st.erase(st.begin());
            long u=top.second;
            
            for(auto it:adj[u])
            {
                long long v=it.first;
                long long wt=it.second;
                
                if(distance[v]>(distance[u])+wt)
                {
                    auto findNode=st.find({distance[v],v});
                    if(findNode!=st.end())
                        st.erase(findNode);
                    
                    distance[v]=(distance[u]+wt);
                    path[v]=path[u];
                    st.insert({distance[v],v});
                }
                else if(distance[v]==distance[u]+wt)
                {
                    path[v]=(path[v]+path[u])%M;
                }
            }
        }
        return path[n-1]%M;
    }
};
*/
class Solution {
public:
    
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
            int ulp_v= getparent(v);
            
            if(ulp_v==ulp_u)
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
        
        
        
        
        
        
        
        
        bool isconnect(int v,int u)
        {
            
            int ulp_u = getparent(u);
            int ulp_v = getparent(v);
            
            
            
            if(ulp_v==ulp_u)
            {
                return true;
            }
            
            
            return false;
            
        }       
        
        
        
        
        
        
    };
    
    
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        
        disjoint_set* ds = new disjoint_set(n);
        vector<bool> visited(n,false);
        int a=0;
        
        for(int i=0;i<connections.size();i++)
        {
            int u = connections[i][0];
            int v = connections[i][1];
            
            //visited[u]=true;
            //visited[v]=true;
            
            if(ds->isconnect(u,v)==false)
            {
                ds->unionbysize(u,v);
                visited[u]=true;
                 visited[v]=true;
            }else{
                
                a++;
            }
            
            
        }
        
       // cout<<"val of a is "<<a<<endl;
        int b=0;
        
        for(int i=0;i<n;i++)
        {
            if(ds->parent[i]==i)
            {
                b++;
            }
        }
        
       // cout<<"no of component are "<<b;
        
        if(a<(b-1))
        {
            return -1;
        }
        
        
        return b-1;
       
        
    }
};
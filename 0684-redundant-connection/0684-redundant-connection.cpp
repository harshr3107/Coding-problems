class Solution {
public:
    
    class disjoint_set
    {
        public: 
      
        
        vector<int> parent;
        vector<int> size;
        
        
        disjoint_set(int n)
        {
            for(int i=0;i<=n;i++)
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
            
            if(size[ulp_v]<size[ulp_u])
            {
                parent[ulp_v]=ulp_u;
                size[ulp_u]+=size[ulp_v];
            }else{
                
                parent[ulp_u]=ulp_v;
                size[ulp_v]+size[ulp_u];
            }
            
            
        }
        
        
        bool isconnect(int v,int u)
        {
            
            int ulp_u = getparent(u);
            int ulp_v = getparent(v);
            
            if(ulp_u==ulp_v)
            {
                return true;
            }
            
            return false;
            
            
        }
        
        
        
        
        
        
        
        
        
        
    };
    
    
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        
        vector<int> ans;
        
        disjoint_set* ds = new disjoint_set(edges.size()+1);
        
        for(int i=0;i<edges.size();i++)
        {
            if(ds->isconnect(edges[i][0],edges[i][1])==false)
            {
                ds->unionbysize(edges[i][0],edges[i][1]);
            }else{
                
                
                ans=edges[i];
                
            }
            
        }
        
        
        return ans;
        
    }
};
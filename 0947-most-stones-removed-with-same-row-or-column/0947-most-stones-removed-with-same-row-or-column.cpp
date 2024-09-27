class Solution {
public:
    
    
    class disjoint_set
    {
        
        public:
        
        vector<int> size;
        vector<int> parent;
        
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
            
            if(size[ulp_v]>size[ulp_u])
            {
                parent[ulp_u]=ulp_v;
                size[ulp_v]+=size[ulp_u];
            }else{
                
                parent[ulp_v]=ulp_u;
                size[ulp_u]+=size[ulp_v];
                
            }
            
            
        }
        
        
        
        bool isconnect(int u,int v)
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
   
    
    
    
    int removeStones(vector<vector<int>>& stones) {
        
        int row = 0;
        int col =0;
        
        for(auto it: stones)
        {
            row = max(row,it[0]);
            col = max(col,it[1]);
            
        }
        
        disjoint_set* ds = new disjoint_set(row+col+1); 
        
        
        for(int i=0;i<stones.size();i++)
        {
            int n1 = stones[i][0];
            int n2 = row+stones[i][1]+1;
            
            if(ds->isconnect(n1,n2)==false)
            {
                ds->unionbysize(n1,n2);
            }
            
        }
        
        //we need to find number of components
        
        int component=0;

        for(int i=0;i<=(row+col+1);i++)
        {
            if(ds->parent[i]==i && ds->size[i]!=1)
            {
                component++;
            }
            
        }
        
        return stones.size()-component;
        
        
        
    }
};
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
        
        
        int findparent(int u)
        {
            if(parent[u]==u)
            {
                return u;
            }
            
            parent[u]= findparent(parent[u]);
            
            return parent[u];
            
        }
        
        
        void unionbysize(int u,int v)
        {
            int ulp_u = findparent(u);
            int ulp_v = findparent(v);
            
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
    
    
    
    
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        
        disjoint_set* ds = new disjoint_set(accounts.size());
        map<string,int>  mp;
        map<int,string> m;
        
        
       
        
        for(int i=0;i<accounts.size();i++)
        {
            m[i]=accounts[i][0];
            
            for(int j=1;j<accounts[i].size();j++)
            {
                 if(mp.count(accounts[i][j])==0)
                 {
                     mp[accounts[i][j]]=i;
                     
                 }else{
                     
                     if(mp[accounts[i][j]]!=i)
                     {
                         
                         ds->unionbysize(mp[accounts[i][j]],i);
                         
                     }
                     
                    
                 }
                
            }
            
        }
        
        
        
        
        
      vector<vector<string>> ans(accounts.size()+1);
        
       for(auto it : mp)
       {
           string mail = it.first;
           int node = it.second;
           int nodepar = ds->findparent(node);
           
           ans[nodepar].push_back(mail);
           
       }
        
        vector<vector<string>> ans1;
        
        int a=0;
        
        for(int i=0;i<ans.size();i++)
        {
            if(ans[i].size()!=0)
            {
                sort(ans[i].begin(),ans[i].end());
                vector<string> v;
                v.push_back(m[i]);
                for(int j=0;j<ans[i].size();j++)
                {
                    v.push_back(ans[i][j]);
                }
               
                ans1.push_back(v);
            }
        }
                
        
        
        return ans1;
        
        
        
    }
};
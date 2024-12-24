class Solution {
public:
    
   
    
    
    void getallcombi(int n,int k,vector<int>& v,vector<vector<int>>& ans)
    {
        
       
        
      
        
        if(k==0)
        {
           
            ans.push_back(v);
            return;
        }
        
        if(n<1)
        {
            return;
        }
        
        
        v.push_back(n);
        getallcombi(n-1,k-1,v,ans);
        v.pop_back();        
        getallcombi(n-1,k,v,ans);
      
      
        
        
        
    }
    
    
    
    vector<vector<int>> combine(int n, int k) {
        
        vector<vector<int>> ans;
        
        vector<int> v;
        
        
        getallcombi(n,k,v,ans);
        
        
        
       return ans; 
    }
};
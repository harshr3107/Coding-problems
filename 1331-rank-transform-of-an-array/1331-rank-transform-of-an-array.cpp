class Solution {
public:
    
   
    
    vector<int> arrayRankTransform(vector<int>& arr) {
        
         vector<int> ans(arr.size());
        
        if(arr.size()==0)
        {
              return ans;
        }
        
        
        vector<pair<int,int>> v;
        
        for(int i=0;i<arr.size();i++)
        {
            v.push_back(make_pair(arr[i],i));
            
        }
        
        
        sort(v.begin(),v.end());
        
       
        int a=1;
        ans[v[0].second]=a;
        
        for(int i=1;i<v.size();i++)
        {
            if(v[i].first!=v[i-1].first)
            {
                a++;
            }
            
            ans[v[i].second]=a;
            
        }
        
        
        
        
        return ans;
    }
};
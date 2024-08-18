class Solution {
public:
    
    
    bool static cmp(pair<int,int> a,pair<int,int> b)
    {
        return a.second>b.second;
    }
    
    
    int maxDistance(vector<vector<int>>& arrays) {
        
        
        vector<pair<int,int>> v;
        
        string s;
        int mini;
        int maxi;
        
        
        for(int i=0;i<arrays.size();i++)
        {
            mini=INT_MAX;
            maxi=INT_MIN;
            
            for(int j=0;j<arrays[i].size();j++)
            {
               mini = min(mini,arrays[i][j]);
               maxi = max(maxi,arrays[i][j]); 
                
                 
            }
            pair<int,int> p;
            p.first=mini;
            p.second=maxi;
            v.push_back(p);
            
            
        }
        
       
        /*
         for(int i=0;i<v.size();i++)
        {
            cout<<v[i].first<<" "<<v[i].second<<endl;
        }*/
        
       // cout<<endl<<endl;
        
        
       sort(v.begin(),v.end());
        
        
        
       
        
        
        int b=INT_MIN;
        
        int a = v[0].first;
        
        //cout<<"here value of a is "<<a<<endl;
        
        for(int i=1;i<v.size();i++)
        {
            b = max(b,abs(v[i].second-a));
        }
        
        //cout<<b<<endl<<endl;;
        
        int h1 = b;
    
        sort(v.begin(),v.end(),cmp);
        
       /*  for(int i=0;i<v.size();i++)
        {
            cout<<v[i].first<<" "<<v[i].second<<endl;
        }*/
        
        //cout<<endl<<endl;
        
        
        
         b=INT_MIN;
        
         a = v[0].second;
        
        //cout<<"here value of a is "<<a<<endl;
        
        for(int i=1;i<v.size();i++)
        {
            b = max(b,abs(a-v[i].first));
        }
        
         //cout<<b<<endl;
        
       int h2 = b;
        
        
        
        
        
      
        
        
        return max(h1,h2);
        
        
    }
};
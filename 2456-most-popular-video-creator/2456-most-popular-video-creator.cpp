class Solution {
public:
    
    class compare{
        
        public: 
        
        bool operator()(pair<string,pair<string,long long>> a,pair<string,pair<string,long long>> b)
        {
            if(a.second.second==b.second.second)
            {
                return a.second.first>b.second.first;
            }
            
            return a.second.second<b.second.second;
            
        }
        
        
    };
    
    
    
    
    vector<vector<string>> mostPopularCreator(vector<string>& creator, vector<string>& id, vector<int>& views) {
        
        unordered_map<string,pair<string,long long>> mp;
        
        
        unordered_map<string,long long> m;
        
        
        
        
        //now create a map so that later can be sent to heap;
        
        for(int i=0;i<creator.size();i++)
        {
           
            
            if(mp.count(creator[i]))
            {
                //cout<<"mai yaha aaya\n";
                
                pair<string,int> p = mp[creator[i]];
                
                if(m[creator[i]]>=views[i])
                {
                   if(m[creator[i]]==views[i])
                   {
                       if(p.first>id[i])
                       {
                           p.first=id[i];
                       }
                   }
                    
                  mp[creator[i]]=make_pair(p.first,p.second+static_cast<long long>(views[i]));
                }else{
                    //cout<<"mai iske aagaya bhai----2\n";
                    mp.erase(creator[i]);
                    
                    mp[creator[i]]=make_pair(id[i],p.second+static_cast<long long>(views[i]));
                    m[creator[i]]=views[i];
                    
                }
            }else{
                
                mp[creator[i]]=make_pair(id[i],views[i]);
                m[creator[i]]=views[i];
            }
            
        }
        
        /*for(auto it: mp)
        {
            cout<<it.first<<" "<<it.second.first<<" "<<it.second.second<<endl;
        }
        
        cout<<endl<<endl;*/
        
        
        priority_queue<pair<string,pair<string,long long>>,vector<pair<string,pair<string,long long>>>,compare> minheap;
        
        
        for(auto it: mp)
        {
            pair<string,pair<string,long long>> q = make_pair(it.first,make_pair(it.second.first,it.second.second));
            minheap.push(q);
            
        }
        
         vector<vector<string>> ans;
        
            string name = minheap.top().first;
            string ide = minheap.top().second.first;
            long long viewe = minheap.top().second.second;
            minheap.pop();
        
        vector<string> v;
        v.push_back(name);
        v.push_back(ide);
        ans.push_back(v);
        v.clear();
        
        while(!minheap.empty() && minheap.top().second.second==viewe)
        {
             name = minheap.top().first;
             ide = minheap.top().second.first;
             viewe = minheap.top().second.second;
             v.push_back(name);
             v.push_back(ide);
             ans.push_back(v);
             v.clear();
             minheap.pop();
        }
        
        
        
       
        
        return ans;
        
    }
};
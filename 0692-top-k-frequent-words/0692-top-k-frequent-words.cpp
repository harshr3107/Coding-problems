class Solution {
public:
    
    class compare{
        
        public:
        
      bool operator()(pair<string,int> a,pair<string,int> b)
      {
           if (a.second == b.second) {
                return a.first < b.first;  
            }
          
          
          return a.second>b.second;
      }
        
    };
    
    
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        
       map<string,int> mp;
        
        for(int i=0;i<words.size();i++)
        {
            mp[words[i]]++;
        }
        
        priority_queue<pair<string,int>,vector<pair<string,int>>,compare> minheap;
        
        
       for(auto it: mp)
       {
           
           if(minheap.size()<k)
           {
               minheap.push(make_pair(it.first,it.second));
           }else{
               
               if(it.second>minheap.top().second)
               {
                   minheap.pop();
                   minheap.push(make_pair(it.first,it.second));
               }
               
               
           }
           
         }
        
        
        vector<string> ans(k);
        
        for(int i=k-1;i>=0;i--)
        {
            
            ans[i]=minheap.top().first;
            minheap.pop();
        }
        
       /* int i=0;
        int j;
        
        while(i<ans.size()-1)
        {
            
            int a = mp[ans[i]];
            j=i+1;
            while(j<ans.size() && mp[ans[j]]==a)
            {
                j++;
            }
            
            
            sort(ans.begin()+i,ans.begin()+j);
            
            i=j;
            
            
            
        }*/
        
        
        
        return ans;
        
        
        
        
        
        
    }
};
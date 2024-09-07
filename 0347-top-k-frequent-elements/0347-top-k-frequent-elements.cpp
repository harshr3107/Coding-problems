class Solution {
public:
    
    
    class compare{
      
        public:
        
        bool operator()(pair<int,int> a,pair<int,int> b)
        {
               return a.second>b.second;
        }
        
        
    };
    
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        map<int,int> mp;
        
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,compare> minheap;
        
        
        int i=0;
       for(auto it: mp)
       {
           
           if(i<k)
           {
               minheap.push(make_pair(it.first,it.second));
               
           }else{
               
               if(it.second>minheap.top().second)
               {
                   minheap.pop();
                   minheap.push(make_pair(it.first,it.second));
                   
               }
               
           }
           
           i++;

               
       }
        
        
        vector<int> ans;
        
        while(!minheap.empty())
        {
            ans.push_back(minheap.top().first);
            minheap.pop();
        }
        
        
        reverse(ans.begin(),ans.end());
        
        return ans;
        
    }
};
class Solution {
public:
    
    
    class compare{
        
        public:
        
        bool operator()(pair<int,int> a,pair<int,int> b)
        {
            
            if(a.second==b.second)
            {
                return a.first>b.first;
            }
            
            
            return a.second>b.second;
        }
        
    };
    
    
    
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,compare> minheap;
        
        for(int i=0;i<arr.size();i++)
        {
            
            
              minheap.push(make_pair(arr[i],abs(x-arr[i])));
            
                
        }
        
        vector<int> ans;
        
       int i=0;
        
        while(i<k)
        {
            //cout<<minheap.top().first<<" "<<minheap.top().second<<endl;
            ans.push_back(minheap.top().first);
            minheap.pop();
            i++;
        }
        
        sort(ans.begin(),ans.end());
        
        
        return ans;
        
        
        
    }
};
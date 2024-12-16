class Solution {
public:
    
    
    
    class compare{
        
        public:
        
        static bool operator()(pair<int,int>& a,pair<int,int>& b)
        {
            
            if(a.first==b.first)
            {
                return a.second>b.second;
            }
            
            return a.first>b.first;
            
            
        }
        
    };
    
    
    
    vector<int> getFinalState(vector<int>& nums, int k, int m) {
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,compare> minheap;
        
        for(int i=0;i<nums.size();i++)
        {
            minheap.push(make_pair(nums[i],i));
            
        }
        
        
        while(!minheap.empty() && k>0)
        {
            
            int a = minheap.top().first;
            int b = minheap.top().second;
            minheap.pop();
            minheap.push(make_pair(a*m,b));
            k--;

        }
        
        vector<int> ans(nums.size());
        
        while(!minheap.empty())
        {
            int a = minheap.top().first;
            int b = minheap.top().second;
            minheap.pop();
            
            ans[b]=a;
           

        }
       
        
        
        return ans;
        
        
        
        
        
        
    }
};
class Solution {
public:
    
    
    class compare
    {
        
        public: 
        bool operator()(pair<int,string>& a,pair<int,string>& b)
        {
            if(a.first==b.first)
            {
                
                for(int i=0;i<a.second.length();i++)
                {
                    if(a.second.at(i)==b.second.at(i))
                    {
                        continue;
                    }
                    
                    return a.second[i]<b.second[i];
                    
                }
                
            }
            
            
            return a.first<b.first;
            
            
            
        }
        
        
    };
    
    
    
    
    string kthLargestNumber(vector<string>& nums, int k) {
        
        priority_queue<pair<int,string>,vector<pair<int,string>>,compare> maxheap;
        
        for(int i=0;i<nums.size();i++)
        {
            
           maxheap.push(make_pair(nums[i].length(),nums[i]));
            
        }
        
        int i=1;
        
        while(i!=k)
        {
            maxheap.pop();
            i++;
        }
        
        return maxheap.top().second;
        
        
        
        
    }
};
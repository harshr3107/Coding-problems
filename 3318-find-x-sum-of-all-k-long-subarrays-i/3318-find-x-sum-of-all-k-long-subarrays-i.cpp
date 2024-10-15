class Solution {
public:
    
    class compare
    {
        public:
        
        bool static operator()(pair<int,int>& a,pair<int,int>& b)
        {
            if(a.second==b.second)
            {
                //cout<<"i entered here for "<<a.first<<" "<<b.first<<endl;
                return a.first<b.first;
            }
            
            return a.second<b.second;
        }
        
        
        
    };
    
    
    
    
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        
        
        map<int,int> mp;
        for(int i=0;i<k;i++)
        {
            mp[nums[i]]++;
        }
        
        int i=0;
        int j=k-1;
        
       
        vector<int> ans;
         
        
        while(j<nums.size())
        {
            
            priority_queue<pair<int,int>,vector<pair<int,int>>,compare> mh;
            for(auto it: mp)
            {
                mh.push(make_pair(it.first,it.second));
            }
            
            int l=0;
            
            int a=0;
            
            while(!mh.empty() && l<x)
            {
               
                a+=((mh.top().first)*(mh.top().second));
                mh.pop();
                l++;
            }
            
            //cout<<"val of ans is "<<a<<endl;
            ans.push_back(a);
            mp[nums[i]]--;
            if(mp[nums[i]]==0)
            {
                mp.erase(nums[i]);
            }
            i++;
            j++;
           
            if(j<nums.size())
            {
                mp[nums[j]]++;
            }
            
           
           
            
            
        }
        
        
        
        
        
        return ans;
                
    }
};
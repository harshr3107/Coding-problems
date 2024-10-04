class Solution {
public:
    
    
   
    
    
    int maxOperations(vector<int>& nums, int k) {
        
       map<int,int> mp;
        int ans=0;
        
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }
        
        int target;
        
        map<int,int>:: iterator it = mp.begin();
        
        for(it = mp.begin();it!=mp.end();it++)
        {
        
           target = k-(it->first);
            
            if(mp.count(target))
            {
                if(target!=(it->first))
                {
                 ans+=min(it->second,mp[target]);
                }else{
                    ans+= (it->second)/2;
                }
                
                mp.erase(target);
            
            
           }
        }
        
        
        return ans;
        
    }
};
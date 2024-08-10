class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
         map<int,int> mp;
        mp[0]=0;
        int sum=0;
        int h=0;
        int size=INT_MAX;
        map<int,int>:: iterator it;
        int b=0;
        int cursize=0;
        
        
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>=target)
            {
                return 1;
            }
            
            
            sum=sum+nums[i];
            mp[sum]=i;
            
            if(sum>=target)
            {
               //cout<<" i entered here-1\n"; 
                b++;
               size = min(size,i+1);
            }
            h = sum-target;
            
            
            it = mp.lower_bound(h);
            
            while(h>0 && it!=mp.begin())
            {
                //cout<<"i entered here\n "<<it->first<<" "<<h<<endl;
                
                if((it->first)<=h)
                {
                    //cout<<"yaha pe aa n\n";
                    
                    b++;
                    cursize = i-(it->second);
                    size = min(size,cursize);
                    //cout<<"yes i am there at "<<i<<" "<<it->second<<endl;
                    break;
                }
                
                it--;
            }
            
            
           
            
            
        }
        
        
        
        if(b==0)
        {
            return 0;
        }
        
        
        return size;
        
        
    }
};
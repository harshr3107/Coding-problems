class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        
        
        //This is giving TLE AT 1229/1235 testcase so logic is right we need a better approach
        
      //lont long ans=1;
       
       /* for(int i=1;i<nums.size();i++)
        {
            int mini = INT_MAX;
            int maxi = INT_MIN;
            
            for(int j=i;j>=0;j--)
            {
                mini = min(nums[j],mini);
                maxi = max(nums[j],maxi);
                
                if(abs(mini-maxi)<=2)
                {
                    ans+=1;
                }else{
                    break;
                }
                    
                
            }
            
           // cout<<"current value of ans is "<<ans<<endl;
            
        }
       
        return ans;*/
        
        long long ans=0;
        
        int i=0;
        int j=0;
        
         priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> minheap;
         priority_queue<pair<int,int>> maxheap;
        
        
        while(j<nums.size())
        {
           // cout<<"mai yaha abder aaya\n";
            
            maxheap.push(make_pair(nums[j],j));
            minheap.push(make_pair(nums[j],j));
            
            while(maxheap.top().second<i)
            {
                maxheap.pop();
            }
            
            while(minheap.top().second<i)
            {
                minheap.pop();
            }
            
            int a = maxheap.top().first;
            int b = minheap.top().first;
            
           // cout<<" at i = "<<i<<" and j = "<<j<<" max - min are "<<a<<" "<<b<<endl;
            
            if(abs(a-b)<=2)
            {
                ans+=(j-i+1);
                
               j++;
                
                
            }else{
                
                i++;
            }
            
           // cout<<"current val of ans is "<<ans<<endl;
            
            
        }
        
        
        return ans;
         
        
         
        
        
        
        
        
        
    }
};
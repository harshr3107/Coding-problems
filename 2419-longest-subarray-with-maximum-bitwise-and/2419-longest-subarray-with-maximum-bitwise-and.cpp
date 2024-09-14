class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        
        
        int a = max_element(nums.begin(),nums.end())-nums.begin();
        //cout<<"the size od the array is "<<nums.size()<<endl;
        //cout<<"value of a is "<<a;
        int maxlen=1;
        int maxi=nums[a];
        
        int i=a;
        int count=0;
        int j=i;
        
           while(i<nums.size())
           {
               j=i;
            
             while(j<nums.size() && nums[j]==maxi)
             {
                count++;
                maxlen=max(maxlen,count);
                j++;
                i=j-1;
             }
                
                count=0;
                i++;
                
            }
            
        return maxlen;
        
        
        
        
        
        
        
        
       /* int maxlen=1;
        int i=0;
        int j=0;
        int maxi=INT_MIN;
        int cur;
        map<int,vector<int>> m;
        
        while(i<nums.size())
        {
            j=i;
            
            cur=nums[j];
            
            
           
            
            while(j<nums.size())
            {
                cur=(cur&nums[j]);
                //cout<<"val for cur is"<<cur<<endl;
                
                  if(maxi<=cur)
                  {
                      //cout<<"i entered here for "<<cur<<endl;
                      
                      maxlen = j-i+1;
                      
                      m[cur].push_back(maxlen);
                      maxi=cur;
                  }
                
                j++;
                
            }
            
            
            
            
            
            i++;
            //cout<<"\ncurrent max is "<<maxi<<" and max len is "<<maxlen<<endl;
            //cout<<endl;
            
        }
        
      
        
        //cout<<"maxi is "<<maxi<<" and "<<m[maxi].size()<<endl;
        
        
        
       int ans = *max_element(m[maxi].begin(),m[maxi].end());
        
        return ans;
        */
        
        
    }
};
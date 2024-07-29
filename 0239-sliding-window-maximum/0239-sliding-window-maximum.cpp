
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        vector<int> ans;
        
        deque<int> q;
        
        
        int i=0;
        
        
        
        while(i<k)
        {
             while(!q.empty() && nums[i]>=nums[q.back()])
             {
                 q.pop_back();
                
             }
            
            q.push_back(i);
            
            i++;
        
            
      }
        
       //cout<<q.size()<<endl;
     ans.push_back(nums[q.front()]);
        
       
       
        while(i<nums.size())
        {
          // cout<<"\ni am entering for "<<nums[i]<<endl;
         
            while(!q.empty() && i-q.front()>=k)
            {
                q.pop_front();
            }
            
             //cout<<"value of feont of queue is "<<q.front()<<endl;
            
            
            while(!q.empty() && nums[i]>nums[q.back()])
            {
                //cout<<"i am here\n";
                q.pop_back();
            }
           
            q.push_back(i);
            ans.push_back(nums[q.front()]);
            
            i++;
            
            
        }
        
        
        
        return ans;
            
            
            
    }
};

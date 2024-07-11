
class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        
        int low=0;
        int high=0;
        bool ans = false;
        int pos=0;
        int steps=0;
        int prehigh=-1;
        
        
        
        while(low<nums.size())
        {
            //cout<<"\nvalue of req is "<<nums[3]<<endl;
            high=low;
            pos=0;
            //cout<<"value of low is "<<low<<endl;
            //cout<<"val of h is "<<high<<endl<<nums[high]<<endl;
            if(nums[high]>0)
            {
                pos++;
               // high+=nums[high];
                
                        nums[high]=nums[high]%nums.size();
                        high=high+nums[high];
                        high=high%nums.size();
                
                //cout<<"val of next high iss "<<high<<endl;
                
                
            }else{
                
                //cout<<"val of high is "<<high<<endl;
                int temp=abs(nums[high])%(nums.size());
                high=high-temp;
                //cout<<"val of high is "<<high<<endl;
                
                if(high<0)
                {
                    high=nums.size()+high;
                }
                
               //cout<<"val of next high is "<<high<<endl;
                
                    
            }
            
            if(high==low)
            {
                low++;
                continue;
            }   
                
            map<int,int> mp;
            
            while(high<nums.size() && high!=low)
            {
                mp[high]++;
                  
                  //cout<<"val of low is "<<low<<endl;
                 // cout<<"val of high is "<<high<<endl;
                
                if(pos>0 && nums[high]<0)
                {
                    //cout<<"i entered here1\n";
                    
                    break;
                }else if(pos==0 && nums[high]>0)
                {
                    //cout<<"i entered here2\n";
                    break;
                }else{
                    
                    
                    if(pos>0)
                    {
                        nums[high]=nums[high]%nums.size();
                        high=high+nums[high];
                        high=high%nums.size();
                        
                     }else{
                        
                       int temp=abs(nums[high])%(nums.size());
                       high=high-temp;
                
                          if(high<0)
                          {
                            high=nums.size()+high;
                            }
                            
                    }
                   }
                
                if(high==low)
                {
                    //cout<<"\n\nvalue of low is "<<low<<endl;
                    ans=true;
                    return ans;
                }
                
                if(mp[high]==1)
                {
                    //return false;
                    break;
                }
                
               
                
                    
                
            }
            
            
            
            
            low++;
            
        }
        
        return ans;
    } 
    
};
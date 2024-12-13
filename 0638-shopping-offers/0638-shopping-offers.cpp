class Solution {
public:
    
    
    bool empty(vector<int>& need)
    {
        for(int i=0;i<need.size();i++)
        {
            if(need[i]>0)
            {
                return false;
            }
            
            
        }
        
        
        return true;
    }
    
    
    map<vector<int>,int> mp;
    
    int getmax(vector<int>& price,vector<vector<int>>& special,vector<int>& need)
    {
        //cout<<" i am here\n";
        
        
        
        
        if(empty(need))
        {
            return 0;
        }
        
        if(mp.count(need))
        {
            return mp[need];
        }
        
       
        
              
               int ans=0;
              
       // cout<<"val of need is "<<need.size()<<endl;
        
               for(int i=0;i<need.size();i++)
               { 
                   
                   ans=ans+(need[i]*price[i]);
                    
               }
        
        //cout<<"mai bahar aaya\n";
             
              
               
              
                for(int coffer=0;coffer<special.size();coffer++)
                {
                    // cout<<"the val of coofer is "<<coffer<<endl;
                      vector<int> temp(need); 
                     int takeoffer=INT_MAX;
                     int a=0;
        
                for(int k=0;k<special[coffer].size()-1;k++)
                {
                  
                   
                    
                    
                    
                    if(need[k]>=special[coffer][k])
                    {
                        temp[k]-=special[coffer][k];
                       
                    }else{
                        a++;
                        break;
                    }
                    
                   
                    
                   
                }
                    
                    if(a==0)
                    {
                     takeoffer = special[coffer].back()+getmax(price,special,temp);
                     ans = min(ans,takeoffer);
                    }
                    
                    
                    
                    
                }
        
         mp[need]=ans;
         return ans;
                
                
            
            
        
        
    }
    
    
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        
        
        //vector<vector<vector<int>>>(.size(),vector<int>())
        
        return getmax(price,special,needs);
        
    }
};
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        
        map<int,int> mp;
        mp[5]=0;
        mp[10]=0;
     
        for(int i=0;i<bills.size();i++)
        {
            if(bills[i]==5)
            {
                mp[bills[i]]++;
                continue;
            }else if(bills[i]==10)
            {
                if(mp[5]<=0)
                {
                    cout<<"i entered here\n";
                    return false;
                }
                mp[5]--;
                mp[10]++;
                
            }else{
                
                
                
                if(mp[10]>0 && mp[5]>0)
                {
                    mp[10]--;
                    mp[5]--;
                   
                }else if(mp[5]>=3)
                {
                    mp[5]=mp[5]-3;
                }else{
                    
                    cout<<"i entered erere-2\n";
                    return false;
                    
                }
                
                mp[20]++;
                
            }
            
        }
        
        
        return true;
        
        
        
    }
};
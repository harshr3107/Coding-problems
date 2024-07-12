class Solution {
public:
    
    
   
    
    
    
  /*  bool ispossible(vector<int> bd, int tflo,int bq,int val)
    {
       //cout<<"\nval is "<<val<<endl;
        int l=0;
        int h=tflo;
        int maxi =*max_element(bd.begin()+l,bd.begin()+h);
        int ans=0;
        
        while(h<bd.size())
        {
           // cout<<"currentmaxi is "<<maxi<<endl;
            
            if(maxi<=val)
            {
                //cout<<"i entered here\n";
                ans++;
                
                if(ans==bq)
                {
                    return true;
                }
                
                
                l=l+tflo;
                h=l+tflo;
                
                //cout<<"l is "<<l<<" and h is "<<h<<endl;
                if(h<=bd.size())
                {
                   maxi =*max_element(bd.begin()+l,bd.begin()+h);
                    //cout<<"maxi is "<<maxi<<endl;
                    if(h==bd.size() && maxi<=val)
                    {
                        ans++;
                    }
                    //maxi = findmaxi(bd,l,h);
                }else{
                   // cout<<"mai yaha aaya\n";
                    break;
                }
              //maxi = findmaxi(bd,l,h);
            }else{
                
                l++;
                h++;
                
               //cout<<"l is "<<l<<" and h is "<<h<<endl; 
                
              maxi =*max_element(bd.begin()+l,bd.begin()+h);
                //if(h==)
               //maxi=findmaxi(bd,l,h);
                
                if((l==bd.size()-1 || h==bd.size()) && maxi<=val )
                {
                    //cout<<"fhdh\n";
                    ans++;
                }
                    
                
            }
            
        }
        
        
        if(ans==bq)
        {
          return true;
        }
        
        return false;
        
        
    }*/
    
    bool ispossible(vector<int>& bloomDay, int m, int k, int day) {
        int total = 0;
        for (int i = 0; i < bloomDay.size(); i++) {
            int count = 0;
            while (i < bloomDay.size() && count < k && bloomDay[i] <= day) {
                count++;
                i++;
            }

            if (count == k) {
                total++;
                i--;
            }

            if (total >= m) {
                return true;
            }
        }

        return false;
    }
    
    
    
    
    
    
    int minDays(vector<int>& bd, int m, int k) {
        
        
        if(bd.size()<(long)m*k)
        {
            return -1;
        }
        
        
       
        
        /*for(int i=0;i<bd.size();i++)
        {
            maxi=max(maxi,bd[i]);
        }*/
        
        int low=1;
        int high= *max_element(bd.begin(),bd.end());
        int mid;
        int ans=-1;
        
        while(high>low)
        {
            
            mid=low+(high-low)/2;
            
            if(ispossible(bd,m,k,mid))
            {
                ans=mid;
                high=mid;
            }else{
                low=mid+1;
            }
            
         }
        
     
        return low;
        
    }
};
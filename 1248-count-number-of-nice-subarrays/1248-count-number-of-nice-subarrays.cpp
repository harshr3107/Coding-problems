class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        
        int low=0;
        int high=0;
        int curlen=0;
        int oddc=0;
        int scount=0;
        int fodd=0;
        
        while(high<nums.size())
        {
            if((nums[high]&1)==1)
            {
                oddc++;
                if(oddc==1)
                {
                    fodd=high;
                }
                if(oddc==k)
                {
                    
                    scount=fodd-low+1;
                    break;
                }
            }
            
            high++;
        }
        
        cout<<"value of fodd is "<<fodd<<endl;
        
        if(high==nums.size())
        {
            return 0;
        }
       
        
        high++;
        //cout<<"value of high is "<<high<<endl;
        
        while(high<nums.size())
        {
           // cout<<"i entered here\n";
            
            if((nums[high]&1)==0)
            {
                //cout<<"i am a even number\n";
                if(oddc==k)
                {
                    scount+=fodd-low+1;
                    //cout<<"value of scount is "<<scount<<endl;
                }
                
                high++;
                
            }else{
                
                //cout<<"i am a odd number\n";
                
                low=fodd+1;
                //cout<<"the new low is "<<low<<endl;
                //oddc--;
                int temp=low;
                while(temp<high && (nums[temp]&1)==0)
                {
                    temp++;
                }
                fodd=temp;
                scount+=fodd-low+1;
                //cout<<"scount is "<<scount<<endl;
                high++;
            }
            
            
        }
        
        
        
        
        return scount;
        
        
    }
};
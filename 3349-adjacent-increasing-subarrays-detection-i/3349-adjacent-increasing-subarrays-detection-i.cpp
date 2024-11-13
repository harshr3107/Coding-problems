class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        
        if(k==1 && nums.size()>1)
        {
            return true;
        }
        
        int i=0;
        int j=0;
        int prev=-1;
        
         while(i<nums.size()-k)
         {
             j=i+1;
            // cout<<"i am here for i = "<<i<<endl;
             if(nums[j]<nums[j-1])
             {
                 //cout<<" mai yaha aaya\n";
                 i++;
                 continue;
             }
             
             int h=1;
             
             while(j<nums.size() && nums[j]>nums[j-1] && h!=k)
             {
                 j++;
                 h++;
             }
             
             if(h==k)
             {
                 //cout<<"i entered here bro "<<j<<endl;   
                 /*if(k==2)
                 {
                     j=j+1;
                 }*/
    
                 h=1;
                 while((j+1)<nums.size() && nums[j]<nums[j+1])
                 {
                     h++;
                     j++;
                     if(h==k)
                     {
                         return true;
                     }
                 }
                 
                 
             }
             
             i++;
             
             
         }
        
        return false;
             
    }
};
class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        
        vector<int> bitc(nums.size(),0);
        
        for(int i=0;i<nums.size();i++)
        {
            int a=nums[i];
            while(a!=0)
            {
                bitc[i]+=(a&1);
                a=(a>>1);
            }
            
        }
        
        
        
        
        
        
        
        for(int i=0;i<nums.size()-1;i++)
        {
           int cind=i;
            
            for(int j=i+1;j<nums.size();j++)
            {
                if(nums[j]<nums[cind])
                {
                    cind=j;
                }
                
            }
            
            if(cind==i)
            {
                continue;
            }else{
                
               // cout<<"i entered here for ind "<<i<<" to swap with "<<cind<<endl;
                
                int a=i;
                int setbits = bitc[i];
                
                //cout<<"the setbits for i is "<<setbits<<endl;
                
                while(a!=cind+1)
                {
                    if(bitc[a]!=setbits)
                    {
                        return false;
                    }
                    a++;
                }
                
                swap(nums[i],nums[cind]);
            }
            
            
        }
        
        
        
        return true;
        
    }
};
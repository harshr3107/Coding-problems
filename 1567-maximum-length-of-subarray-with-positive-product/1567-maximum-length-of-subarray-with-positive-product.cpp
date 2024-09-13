class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        
        int a=0;
        int curlen=0;
        int maxlen=0;
        int sindex=0;
        int findex=0;
        
        for(int i=0;i<nums.size();i++)
        {
            //cout<<"cur val of a is "<<a<<" and sindex is "<<sindex<<" and findex is "<<findex<<endl;
            
            if(nums[i]==0)
            {
                
                 if(a%2==0)
                {
                    maxlen=max(maxlen,i-sindex-1);
                }else{
                    maxlen=max(maxlen,i-findex-1);
                } 
                
                
                sindex=i+1;
                findex=i+1;
                a=0;
                
                
            }else if(nums[i]<0)
            {
                a++;
                if(a==1)
                {
                    findex=i;
                }
                
                 if(a%2==0)
                {
                    maxlen=max(maxlen,i-sindex+1);
                }
                
                
            }else{
                
                 maxlen=max(maxlen,1);
                 if(a%2==0)
                {
                    maxlen=max(maxlen,i-sindex+1);
                }else{
                    maxlen=max(maxlen,i-findex);
                } 
                
                
            }
            
                
            
        }
        
        
        return maxlen;
        
        
        
    }
};
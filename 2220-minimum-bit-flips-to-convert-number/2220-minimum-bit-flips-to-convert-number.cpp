class Solution {
public:
    int minBitFlips(int start, int goal) {
        
       int c = start^goal;
        int ans=0;
        
        while(c!=0)
        {
            if(c&1==1)
            {
                ans++;
            }
            
            c=(c>>1);
        }
        
        
        return ans;
        
    }
};
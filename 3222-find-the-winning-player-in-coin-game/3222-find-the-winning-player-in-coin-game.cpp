class Solution {
public:
    string losingPlayer(int x, int y) {
        
        if(y<4)
        {
            return "Bob";
        }
        
        
       int a=0;
        while(x>0 && y/4>=1)
        {
            a++;
            x=x-1;
            y=y-4;
        }
        
        
        if((a&1)==1)
        {
            return "Alice";
        }
        
        
        
            return "Bob";
        
           
        
        
    }
};
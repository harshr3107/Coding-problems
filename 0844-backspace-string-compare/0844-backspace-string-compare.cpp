class Solution {
public:
    bool backspaceCompare(string s, string t) {
        
        int i=0;
        
        while(i<s.length())
        {
        
            if(s.at(i)=='#')
            {
                if(i==0)
                {
                    s.erase(0,1);
                    i=-1;
                }else{
                    
                    i--;
                    s.erase(i,2);
                    i--;
                    
                }
            }
            
            
            i++;
         
            
            
        }
        
        i=0;
        
        while(i<t.length())
        {
        
            if(t.at(i)=='#')
            {
                if(i==0)
                {
                    t.erase(0,1);
                    i=-1;
                }else{
                    
                    i--;
                    t.erase(i,2);
                    i--;
                    
                }
            }
            
            
            i++;
         
            
            
        }
        
        if(s==t)
        {
            return true;
        }
       
        
        
        return false;
        
        
        
    }
};
class Solution {
public:
    string reverseStr(string s, int k) {
        
        int i=0;
        int j=2*k-1;
        int h=0;
        
        while(j<s.length())
        {
            h=i+k-1;
        
           
            int x=i;
            int y=h;
            
            while(y>x)
            {
                swap(s.at(x),s.at(y));
                x++;
                y--;
            }
            
            i=j+1;
            j=i+2*k-1;
           
     }
        
        
        if(i<s.length())
        {
            
            if(s.length()-i>=k)
            {
                int x=i;
                int y = i+k-1;
                
            while(y>x)
            {
                swap(s.at(x),s.at(y));
                x++;
                y--;
            }
                
                
                
                
            }else{
                
                int x=i;
                int y=s.length()-1;
                  while(y>x)
                  {
                      swap(s.at(x),s.at(y));
                      x++;
                      y--;
                  }
                
                
            }
            
            
            
        }
        
        
        return s;
        
        
    }
};
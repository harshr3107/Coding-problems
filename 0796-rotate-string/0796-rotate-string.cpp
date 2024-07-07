class Solution {
public:
    
    
   
   
    
    
    bool rotateString(string s, string goal) {
        
        int h = s.length();
        
      
        for(int i=0;i<s.length();i++)
        {
            char temp = s.at(0);
            s = s.substr(1,h-1);
            s+=temp;
            
            if(s==goal)
            {
                return true;
            }
           
        }
      
        
        
        return false;
        
        
    }
};
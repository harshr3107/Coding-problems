class Solution {
public:
    string largestOddNumber(string s) {
        
        int h = s.length();
        
        while(h!=0)
        {
            int n = s.at(h-1)-'0';
            if(n&1)
            {
                return s.substr(0,h);
            }
            
            h--;
            
            
        }
        
        
        return "";
        
    }
};
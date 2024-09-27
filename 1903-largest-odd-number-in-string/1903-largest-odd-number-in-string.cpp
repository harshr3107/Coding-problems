class Solution {
public:
    string largestOddNumber(string num) {
        
        int i;
        int b=0;
        for(i=num.size()-1;i>=0;i--)
        {
            int a = num.at(i)-'0';
            if((a&1)==1)
            {
                b++;
                break;
                
            }
            
        }
        
        
        if(b==0)
        {
            return "";
        }
        
        return num.substr(0,i+1);
        
    }
};
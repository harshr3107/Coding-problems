class Solution {
public:
    string removeDigit(string number, char digit) {
        
        int a=0;
        
        for(int i=0;i<number.length();i++)
        {
            if(number[i]==digit)
            {
                a=i;
                if(i<number.length()-1 && number[i]<number[i+1])
                {
                    return number.erase(i,1);
                    
                }
                
            }
        }
        
        
        return number.erase(a,1);
        
        
    }
};
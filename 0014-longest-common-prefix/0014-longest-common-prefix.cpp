class Solution {
public:
    string longestCommonPrefix(vector<string>& str) {
        
        string ans="";
        int i=0;
        char ch;
        
        while(true)
        {
            if(i<str[0].length())
            {
              ch=str[0].at(i);
                
            }else{
                return ans;
            }
            
            int a=1;
            
            for(int j=1;j<str.size();j++)
            {
                if(i<str[j].length())
                {
                if(str[j].at(i)==ch)
                {
                    a++;
                }
                }else{
                    return ans;
                }
                
                
            }
            
            if(a==str.size())
            {
                ans+=ch;
            }else{
               return ans;
            }
            
            i++;
            
            
            
        }
        
        
        
        
        return ans;
        
        
    }
};
class Solution {
public:
    string removeOccurrences(string s, string part) {
        
        int i=0;
        int sublen= part.length();
        
        while(i<s.length())
        {
            cout<<"value of  string is "<<s<<endl;
            
            if(s.substr(i,sublen)==part)
            {
                s.erase(i,sublen);
                
                if(i-(sublen-1)>0)
                {
                    i=i-(sublen-1);
                }else{
                    i=0;
                }
                
                
            }else{
                i++;
            }
            
            
            
        }
        
        return s;
        
        
        
        
    }
};
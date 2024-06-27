class Solution {
public:
    string removeOccurrences(string s, string part) {
        
        
        //this question could have been done with the help of find function
        
                   while(s.length()!=0 && s.find(part)<s.length())
                   {
                        s.erase(s.find(part),part.length());
                   }
                   
                   return s;
        
        
        
        /*
        
        int i=0;
        int sublen= part.length();
        
        while(i+sublen<=s.length())
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
        
        
        */
        
        
        
    }
};
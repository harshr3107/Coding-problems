class Solution {
public:
    string removeDuplicates(string s) {
        
        int i=0;
        while(s.length()!=0 && i<s.length()-1)
        {
            if(s.at(i)==s.at(i+1))
            {
                s.erase(i,2);
                
                if(i!=0)
                {
                  i=i-1;
                }
                
                
            }else{
                
                i++;
            }
            
        }
        
        return s;
        
    }
};
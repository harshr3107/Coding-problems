class Solution {
public:
    bool isPalindrome(string s) {
        
       
        
        string h="";
        
        for(int i=0;i<s.length();i++)
        {
            if((s.at(i)>='a' && s.at(i)<='z') || (s.at(i)>='A' && s.at(i)<='Z') || (s.at(i)>='0' && s.at(i)<='9'))
            {
                h+=tolower(s.at(i));
            }
            
        }
        
        cout<<h.length()<<endl;
        
        if(h.length()==0)
        {
            return true;
        }
        
        cout<<h<<endl;
        
        int i=0;
        
        
        while(i<=h.length()/2)
        {
            if(h.at(i)!=h.at(h.length()-i-1))
            {
                cout<<"i entered heere for "<<h[i]<<" and "<<h[h.length()-i-1]<<endl;
                return false;
            }
            
            i++;
        }
        
        
        return true;
        
        
    }
};
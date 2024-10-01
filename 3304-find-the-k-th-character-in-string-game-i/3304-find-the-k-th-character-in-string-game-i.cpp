class Solution {
public:
    char kthCharacter(int k) {
        
        string s = "a";
        
        while(s.length()<k)
        {
            //cout<<"the length of sting is "<<s.length()<<endl;
            
            string b="";
            int i=0;
            while(i<s.length())
            {
                char c = s.at(i);
                c++;
                b+=c;
                i++;
            }
            
            s=s+b;
        }
        
        
        return s.at(k-1);
    }
};
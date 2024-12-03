class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        
        string newstr="";
        newstr+=s.substr(0,spaces[0]);
        newstr+=" ";
        int h;
        int m;
        int i=0;
        for(i=1;i<spaces.size();i++)
        {
             h = spaces[i-1];
             m = spaces[i]-spaces[i-1];
            
            newstr+=s.substr(h,m);
            newstr+=" ";
            
            
        }
        
        newstr+=s.substr(spaces[i-1]);
        
        
        return newstr;
        
    }
};
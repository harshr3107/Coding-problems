class Solution {
public:
    
    
    bool isvowel(char a)
    {
       
        if(a=='a' || a=='e' || a=='i' || a=='o' || a=='u' || a=='A' || a=='E' || a=='I' || a=='O' || a=='U')
        {
            return true;
        }
        
       return false;
        
        
    }
    
    
    
    
    string sortVowels(string s) {
        
        vector<int> v;
        vector<char> c;
        string t;
        
        for(int i=0;i<s.length();i++)
        {
            
            if(isvowel(s.at(i)))
            {
                v.push_back(i);
                c.push_back(s.at(i));
                //cout<<s.at(i)<<" "<<endl;
                
            }
            
        }
        
        sort(c.begin(),c.end());
        
        
        for(int i=0;i<v.size();i++)
        {
            //cout<<c[i]<<" ";
            s.at(v[i])=c[i];
        }
        
        
        
        return s;
        
        
        
    }
};
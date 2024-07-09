class Solution {
public:
    int numberOfSubstrings(string s) {
        
        map<char,int> m;
        int i;
        int h=0;
        for(i=0;i<s.length();i++)
        {
            m[s.at(i)]++;
            
            if(m.count('a') && m.count('b') && m.count('c'))
            {
                h++;
                break;
            }
            
        }
        
        int ans=0;
        
        if(h==0)
        {
            return ans;
        }
        
        
        int low=0;
        int high=i;
        
        
       
        
        while(high<s.length())
        {
            
            
            
            while(high>low && m['a']>=1 && m['b']>=1 && m['c']>=1)
            {
               
                m[s.at(low)]--;
                
                low++;
            }
           
            low=low-1;
            m[s.at(low)]++;
            ans+=low+1;
            
            high++;
            if(high<s.length())
            {
              m[s.at(high)]++;
            }
            
            
            
            
        }
        
        
        return ans;
        
        
        
    }
};
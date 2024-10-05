class Solution {
public:
    
    
    bool checkInclusion(string s1, string s2) {
        
        if(s1.length()>s2.length())
        {
            return false;
        }
        
        
        map<char,int> mp1;
        map<char,int> mp2;
        
        for(int i=0;i<s1.length();i++)
        {
            mp1[s1.at(i)]++;
            mp2[s2.at(i)]++;
        }
        
        
        
          
            
       
        
        int i=0;
        int j=s1.length()-1;
        
       
        while(j<s2.length()-1)
        {
            
            if(mp1==mp2)
            {
                return true;
            }
            
            mp2[s2.at(i)]--;
            if(mp2[s2.at(i)]==0)
            {
                mp2.erase(s2.at(i));
            }
            i++;
            j++;
            
            mp2[s2.at(j)]++;
            
           
            
        }
        
        if(mp1==mp2)
        {
            return true;
        }
        
        
        return false;
        
    }
};
class Solution {
public:
    
    
    bool checkVowel(char c)
    {
        if(c=='a' || c=='A' || c=='e' || c=='E' || c=='I' || c=='i' || c=='o' || c=='O' || c=='u' || c=='U')
        {
            return true;
        }
        
        
        return false;
        
        
    }
    
    
    string reverseVowels(string s) {
        
        int low=0;
        int high=s.length()-1;
        int slen = s.length();
        
        cout<<s.length()<<endl;
        
        while(high>low)
        {
            
            while(low<high && !checkVowel(s.at(low)))
            {
            
                low++;
            }
            
            
            
            
            
            while(high>low && !checkVowel(s.at(high)))
            {
                
               
                
                high--;
            }
            
          
            
            swap(s.at(low),s.at(high));
            low++;
            high--;
            
            
            
            
            
        }
        
        return s;
        
    }
};
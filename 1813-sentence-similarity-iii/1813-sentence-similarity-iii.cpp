class Solution {
public:
    
    
        
    
    
    
    
    
    bool areSentencesSimilar(string sentence1, string sentence2) {
        
        
        if(sentence1.length()>sentence2.length())
        {
            string temp = sentence2;
            sentence2=sentence1;
            sentence1=temp;
        }
        
        
        
        stringstream s1(sentence1);
        stringstream s2(sentence2);
        
        string word;
        
        vector<string> v1;
        vector<string> v2;
        
        while(s1>>word)
        {
            v1.push_back(word);
        }
        
        while(s2>>word)
        {
            v2.push_back(word);
        }
        
        
        
      int i1=0;
      int j1=v1.size()-1;
      int i2=0;
      int j2=v2.size()-1;
        
        while(i1<=j1)
        {
            if(v1[i1]==v2[i2])
            {
                i1++;
                i2++;
                
            }else if(v1[j1]==v2[j2])
            {
                j1--;
                j2--;
                
            }else{
                
                return false;
            }
            
            
        }
        
      
        return true;
        
        
    }
};
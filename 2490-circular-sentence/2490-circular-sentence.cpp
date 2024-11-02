class Solution {
public:
    bool isCircularSentence(string sentence) {
        
        stringstream ss(sentence);
        char firstchar=sentence.at(0);
        
        char prevchar;
        string word;
        
        int count=0;
        
        while(ss>>word)
        {
            if(count!=0)
            {
                if(word.at(0)!=prevchar)
                {
                    return false;
                }
                
                
            }
                
                prevchar=word.at(word.length()-1);
            
            
            count++;
            
            
        }
        
        if(prevchar!=firstchar)
        {
            return false;
        }
        
        
        return true;
        
    }
};
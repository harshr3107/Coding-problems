class Solution {
public:
    int isPrefixOfWord(string sentence, string sw) {
        
        int l = sw.length();
        
        stringstream ss(sentence);
        
        string word;
        int a=1;
        
        while(ss>>word)
        {
           if(word.substr(0,l)==sw)
           {
               return a;
           }
            a++;
        }
        
        
        return -1;
        
        
        return 4;
            
        
    }
};
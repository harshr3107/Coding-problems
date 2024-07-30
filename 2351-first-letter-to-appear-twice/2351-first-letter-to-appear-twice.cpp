class Solution {
public:
    char repeatedCharacter(string s) {
        
        vector<int> count(26);
        
        queue<char> q;
        
        int i=0;
        
        while(i<s.length())
        {
            
            count[s.at(i)-'a']++;
            
            if(count[s.at(i)-'a']==2)
            {
                return s.at(i);
            }
            
            i++;
        }
        
        
        return 'a';
        
        
    }
};
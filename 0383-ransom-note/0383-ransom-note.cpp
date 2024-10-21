class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        
        
        map<char,int> mp1;
        map<char,int> mp2;
        
        
        
        for(int i=0;i<ransomNote.length();i++)
        {
            mp1[ransomNote.at(i)]++;
        }
        
        for(int i=0;i<magazine.length();i++)
        {
            mp2[magazine.at(i)]++;
        }
        
        
        int i=0;
        while(i<ransomNote.length())
        {
            if(mp1[ransomNote.at(i)]>mp2[ransomNote.at(i)])
            {
                return false;
            }
            i++;
        }
        
        return true;
        
        
        
        
    }
};
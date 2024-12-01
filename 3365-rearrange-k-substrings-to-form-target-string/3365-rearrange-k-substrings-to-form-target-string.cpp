/*class Solution {
public:
    bool isPossibleToRearrange(string s, string t, int k) {
        
       multiset<string> str1;
       multiset<string> str2; 
        
        int reqlen = s.length()/k;
        
        
        int i=0;
       
        
        while(i<k)
        {
            string temp = s.substr(0,reqlen);
            str1.insert(temp);
            s=s.substr(reqlen);
            
            temp = t.substr(0,reqlen);
            str2.insert(temp);
            t=t.substr(reqlen);
            
            
            i++;
            
        }
        
        
        
        
        if(str1==str2)
        {
            return true;
        }
     
        
        
        return false;
        
        
        
    }
};*/


class Solution {
public:
    bool isPossibleToRearrange(string s, string t, int k) {
        // Check divisibility and length conditions
        if (s.length() != t.length() || s.length() % k != 0) {
            return false;
        }
        
        int reqlen = s.length() / k; // Length of each partition
        
        multiset<string> str1, str2;

        // Use indices to extract substrings without creating new copies
        for (int i = 0; i < s.length(); i += reqlen) {
            str1.insert(s.substr(i, reqlen)); // Insert partition from s
            str2.insert(t.substr(i, reqlen)); // Insert partition from t
        }
        
        // Compare multisets
        return str1 == str2;
    }
};

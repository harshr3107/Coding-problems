class Solution {
public:
    char findTheDifference(string s, string t) {
        
      int ans=0;
        
        for(int i=0;i<s.length();i++)
        {
            ans=(ans^s.at(i)^t.at(i));
        }
        
        ans=(ans^t.at(s.length()));
        
        return ans;
        
    }
};
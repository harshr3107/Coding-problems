class Solution {
public:
    void reverseString(vector<char>& s) {
        
        if(s.size()==1)
        {
            return;
        }
        
        int h=s.size();
        
        
        for(int i=0;i<h/2;i++)
        {
            swap(s[i],s[s.size()-i-1]);
        }
        
        
        
        
    }
};
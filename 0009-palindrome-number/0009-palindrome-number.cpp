class Solution {
public:
    bool isPalindrome(int x) {
        
        
        if(x<0)
        {
            return false;
        }
        
        
        string str = to_string(x);
        
        
      cout<<str.length()<<endl;
        
        for(int i=0;i<str.length()/2;i++)
        {
            if(str.at(i)!=str.at(str.length()-i-1))
            {
                return false;
            }
        }
        
        
        
        return true;
        
    }
};
class Solution {
public:
    
    bool ispalindrome(string s)
    {
        //cout<<"string is "<<s<<endl;
        for(int i=0;i<=s.length()/2;i++)
        {
            if(s.at(i)!=s.at(s.length()-i-1))
            {
                return false;
            }
        }
        
        return true;
    }
    
    
    
    
    int countSubstrings(string s) {
        
        int i=0;
        int j=i+1;
        
        int a=s.length();
        
        
        
        while(i<s.length()-1)
        {
            //cout<<"value of i is "<<i<<endl;
            //cout<<"value of j is "<<j<<endl;
            
            if(ispalindrome(s.substr(i,j-i+1)))
            {
                a++;
            }
            
            j++;
            if(j==s.length())
            {
                //cout<<"\ni entered here\n";
                i++;
                j=i+1;
            }
        }
        
        
        return a;
        
        
    }
};
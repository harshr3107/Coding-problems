class Solution {
public:
    int longestSubstring(string s, int k) {
        
        
        if(s.length()<=0)
        {
            return 0;
        }
        
        map<char,int> mp;
        
        //cout<<"the current string is "<<s<<endl;
        
        
        for(int i=0;i<s.length();i++)
        {
            mp[s.at(i)]++;
        }
        
        int ans = INT_MIN;
        int leftpart=s.length();
        int rightpart=0;
        
        for( int i=0;i<s.length();i++)
        {
            
            
            if(mp[s.at(i)]<k)
            {
                
                   leftpart =  longestSubstring(s.substr(0,i),k);
                    rightpart = longestSubstring(s.substr(i+1),k);
                break;
                
            }
            
        }
        
        return max(leftpart,rightpart);
        
        
        
    }
};
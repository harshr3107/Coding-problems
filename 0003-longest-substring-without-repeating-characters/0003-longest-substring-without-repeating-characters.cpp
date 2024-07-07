class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        vector<int> v(129,0);
        
        if(s.length()==0)
        {
            return 0;
        }
        
        
        int low=0;
        int high=0;
        int curlen=0;
        int maxlen = INT_MIN;
        
        
        
        while(high<s.length())
        {
            if(v[s.at(high)-' ']==0)
            {
               
                v[s.at(high)-' ']++;
                 high++;
                maxlen = max(maxlen,high-low);
                
            }else{
                
                char a = s.at(high);
                
                while(low<high && s.at(low)!=a)
                {
                    v[s.at(low)-' ']--;
                    low++;
                }
                
                if(low!=s.length() && low!=high)
                {
                    v[s.at(low)-' ']--;
                    low++;
                }else{
                    high++;
                }
                
                
                
                
            }
            
        }
        
        
        return maxlen;
        
        
        
        
    }
};
class Solution {
public:
    int numberOfSubstrings(string s, int k) {
        
        map<char,int> mp;
        
        int i=0;
        int j=0;
        
        int ans=0;
        
        
        while(i<s.length())
        {
            j=i;
            
            while(j<s.length())
            {
                mp[s.at(j)]++;
                if(mp[s.at(j)]==k)
                {
                   // cout<<"i entered for "<<i<<" where j = "<<j<<endl;
                    
                    ans+=(s.length()-j);
                    break;
                }
                
                j++;
                
            }
            
            
            mp.clear();
            i++;
            
            
        }
        
      
        
        return ans;
        
    }
};
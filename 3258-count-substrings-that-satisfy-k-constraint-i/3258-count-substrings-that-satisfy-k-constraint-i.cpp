class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        
        map<char,int> m;
        
        int i=0;
        int j=0;
        
        int ans=0;
        
        while(j<s.length())
        {
            
            m[s.at(j)]++;
            
            while(m['1']>k && m['0']>k)
            {
                m[s.at(i)]--;
                i++;
                
            }
            
            ans=ans+(j-i+1);
            j++;
            
            
            
        }
        
        
        return ans;
        
    }
};
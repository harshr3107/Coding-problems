class Solution {
public:
    int numberOfSubstrings(string s) {
        
        map<char,int> m;
        int i;
        int h=0;
        for(i=0;i<s.length();i++)
        {
            m[s.at(i)]++;
            
            if(m.count('a') && m.count('b') && m.count('c'))
            {
                h++;
                break;
            }
            
        }
        
        int ans=0;
        
        if(h==0)
        {
            return ans;
        }
        
        
        int low=0;
        int high=i;
        
        
       // cout<<"value of low "<<low<<" value of high is "<<high<<endl;
        
        while(high<s.length())
        {
            
            
            
            while(high>low && m['a']>=1 && m['b']>=1 && m['c']>=1)
            {
                //cout<<m.count('a')<<" "<<m.count('b')<<" "<<m.count('c')<<endl;
                m[s.at(low)]--;
                //cout<<m.count('a')<<" "<<m.count('b')<<" "<<m.count('c')<<endl;
                low++;
            }
           // cout<<"val of low is "<<low<<endl;
            
            low=low-1;
            
             //cout<<"val of low is "<<low<<endl;
            
            //cout<<"value of low "<<low<<" value of high is "<<high<<endl;
            
            m[s.at(low)]++;
            ans+=low+1;
            
            high++;
            if(high<s.length())
            {
              m[s.at(high)]++;
            }
            
            
            
            
        }
        
        
        return ans;
        
        
        
    }
};
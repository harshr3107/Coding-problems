class Solution {
public:
    int maximumLength(string s) {
        
        
        map<string,int> mp;
        int ans = -1;
        string h="";
        
        for(int i=0;i<s.length();i++)
        {
           string h="";
            
            for(int j=i;j<s.length();j++)
            {
              
                if(s.at(i)==s.at(j))
                {
                    h+=s.at(j);
                    //cout<<"string  is "<<h<<endl;
                    mp[h]++;
                    if(mp[h]>=3)
                    {
                        ans = max(ans,static_cast<int>(h.length()));
                    }
                    
                }else{
                    
                    break;
                }
                
                
              
            }
            
        }
        
        
       
        
        
        return ans;
        
        
    }
};
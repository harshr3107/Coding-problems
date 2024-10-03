class Solution {
public:
    string convert(string s, int n) {
        
        
        if(n==1)
        {
            return s;
        }
        
        
        
       vector<string> ans(n,"");
        
        int i=0;
        int l=0;
        int flag=false;
        
        while(l<s.length())
        {
            ans[i].push_back(s.at(l));
            
            
            if(i==n-1)
            {
               flag=true;
                i--;
                l++;
                continue;
            }
            
            if(i==0)
            {
                flag=false;
                i++;
                l++;
                continue;
                
            }
            
            if(flag)
            {
                i--;
                
            }else{
                
                i++;
            }
            
            
            l++;
            
        }
        
        string h="";
        
        for(int i=0;i<ans.size();i++)
        {
          h+=ans[i];
        }
        
        
        return h;
        
    }
};
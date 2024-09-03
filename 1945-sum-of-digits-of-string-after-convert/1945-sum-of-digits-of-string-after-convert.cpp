class Solution {
public:
    int getLucky(string s, int k) {
        
        
        string ans="";
        
        for(int i=0;i<s.length();i++)
        {
            int h = s.at(i)-'a'+1;
            ans+=to_string(h);
        }
        
        int h;
        
        
        while(k>0)
        {
           
            h=0;
            for(int i=0;i<ans.length();i++)
            {
              int a = ans.at(i)-'0';
              h+=a;
            }
            
            ans = to_string(h);
            k--;
            
            
            
        }
        
        
        
       // cout<<"value of ans is "<<ans<<endl;
        
        return h;
        
        
    }
};
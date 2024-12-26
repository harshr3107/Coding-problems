class Solution {
public:
    
    bool checkstring(string s,set<string>& st,unordered_map<string,int>& mp)
    {
        
        if(mp.count(s))
        {
            return mp[s];
        }
        
        if(st.count(s))
        {
            return true;
        }
        
        if(s.length()==1)
        {
            return false;
        }
        
        int ans=false;
        
        for(int i=0;i<s.length();i++)
        {
            string left = s.substr(0,i+1);
            string right = s.substr(i+1);
            
            
            if(st.count(left))
            {
                ans =  true&checkstring(right,st,mp);
                if(ans==true)
                {
                    mp[s]=true;
                    return true;
                }
               
            }
            
            
        }
        
        mp[s]=ans;
       
        return ans;
        
        
    }
    
    
    
    
    
    
    bool wordBreak(string s, vector<string>& w) {
        
        set<string> st(w.begin(),w.end());
        unordered_map<string,int> dp;
       return checkstring(s,st,dp);
        
        
    }
};
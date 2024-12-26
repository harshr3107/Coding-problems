class Solution {
public:
    
    
    int getminimum(string s,set<string>& st, unordered_map<string,int>& dp)
    {
        //cout<<"i entered here for string "<<s<<endl;
        
        if(dp.count(s))
        {
            return dp[s];
        }
        
        
        if(st.count(s))
        {
            return 0;
        }
        
        if(s.length()==1)
        {
            return 1;
        }
        
        
        
        
        int ans=1e9+7;
        
        
        
        for(int i=0;i<s.length();i++)
        {
            string left =  s.substr(0,i+1);
            string right = s.substr(i+1);
            
            if(st.count(left))
            {
                ans = min(ans,getminimum(right,st,dp));
                
            }else{
                
                ans = min(ans,static_cast<int>(left.length())+getminimum(right,st,dp));
                
            }
            
            
            
        }
        
        dp[s]=ans;
        return ans;
        
        
    }
   
    
    int minExtraChar(string s, vector<string>& d) {
        
        
       set<string> st(d.begin(),d.end());
        unordered_map<string,int> dp;
        
        return getminimum(s,st,dp);
        
        
        
        return 0;
        
    }
};
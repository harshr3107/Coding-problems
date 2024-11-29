class Solution {
public:
    
    
    bool checkpalindrome(string s)
    {
        for(int i=0;i<s.length()/2;i++)
        {
            if(s.at(i)!=s.at(s.length()-i-1))
            {
                return false;
            }
        }
        
        return true;
        
    }
    
    
    
    
    void checkforall(string s,vector<string>& v,vector<vector<string>>& ans)
    {
        
        if(s.length()==0)
        {
            ans.push_back(v);
            return;
        }
        
        
        for(int i=0;i<s.length();i++)
        {
              string cur = s.substr(0,i+1);
            
              if(checkpalindrome(cur))
              {
                  v.push_back(cur);
                  checkforall(s.substr(i+1),v,ans);
                  v.pop_back();
                  
              }
            
        }
    
    
    }
    
    
    
    
    
    
    
    vector<vector<string>> partition(string s) {
        
        vector<vector<string>> ans;
        vector<string> v;
        string cur;
        checkforall(s,v,ans);
        
        return ans;
        
        
    }
};
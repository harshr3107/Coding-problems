class Solution {
public:
    
    /*bool contains(string p,int j)
    {
            //cout<<"i entered here\n";
        
       int a=0;
        
        for(int i=j;i<p.length();i++)
        {
            a++;
            if(p.at(i)!='*')
            {
                return false;
            }
        }
        
        return a==0?false:true;
        
        //return true;
    }*/
    
    
    
    bool ismatch(string s,string p,int i,int j,vector<vector<int>>& dp)
    {
        
        //cout<<"value of i and j is "<<i<<" "<<j<<endl;
        
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        
        
        if((i==s.length() && j==p.length()))
        {
            //cout<<"yaha true hua mai\n";
            dp[i][j]=1;
            return true;
        }
        
        if (i == s.length()) {
            for (int k = j; k < p.length(); k++) {
                if (p[k] != '*') return dp[i][j] = 0;
            }
            return dp[i][j] = 1;
        }
        
        if(i>=s.length() || j>=p.length())
        {
            dp[i][j]=0;
            return false;
        }
        
      
        
        
        if(s.at(i)==p.at(j) || p.at(j)=='?')
        {
            //cout<<"entered 1\n";
            if(ismatch(s,p,i+1,j+1,dp)==true)
            {
                dp[i][j]=1;
                return true;
            }
        }else if(p.at(j)=='*')
        {
           // cout<<"entered 2\n";
            //* is empty
            if(ismatch(s,p,i,j+1,dp)==true || ismatch(s,p,i+1,j,dp)==true)
            {
                dp[i][j]=1;
                return true;
            }
            
            //check for all sequences that may belong to the given string
            /*for(int k=i;k<s.length();k++)
            {
                if(ismatch(s,p,k+1,j+1,dp)==true)
                {
                    dp[i][j]=1;
                    return true;
                }
            }*/
            
            
        }
        
        dp[i][j]=0;
        return false;
        
        
        
    }
    
    
    
    
    
    
    
    
    
    
    
    bool isMatch(string s, string p) {
        
        //cout<<s.length()<<" "<<p.length()<<endl;
        
        int i=0;
        int j=0;
        vector<vector<int>> dp(s.length()+1,vector<int>(p.length()+1,-1));
        
        return ismatch(s,p,i,j,dp);
        
    }
};
/*class Solution {
public:
    string longestPalindrome(string s) {
        
        if(s.length()==1)
        {
            return s;
        }
        
       vector<vector<int>> dp(s.length()+2,vector<int>(s.length()+2,0));
        int ans=INT_MIN;
        int a=-1;
        int b=-1;
        
        for(int i=1;i<s.length();i++)
        {
            
            for(int j=s.length();j>=i;j--)
            {
                
                
                
                
                if(i==j)
                {
                    
                    
                    dp[i][j]=1+dp[i-1][j+1];
                    cout<<dp[i][j]<<" "<<endl;
                    ans=max(ans,dp[i][j]);
                    if(ans==dp[i][j])
                    {
                        a=i-1;
                    }
                    
                   
                  
                    continue;
                }
                
                if(s.at(i-1)==s.at(j-1))
                {
                    
                    dp[i][j]=2+dp[i-1][j+1];
                    
                    
                    ans=max(ans,dp[i][j]);
                    if(ans==dp[i][j])
                    {
                        a=i-1;
                    }
                    
                    continue;
                    
                }
                
            }
            
            
        }
        
        
        
        
       
        
        
        
       
       cout<<ans<<" "<<a<<endl;
        
        if((ans&1)==1)
        {
            a=a-(ans/2);
            //cout<<"new val of a is "<<a<<endl;
        }else{
            
           int h =ans-2;
            a=a-(h/2);
        }
        
        return s.substr(a,ans);
        
        
    }
};*/

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        
        if (n <= 1) {
            return s;
        }
        
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        int maxLength = 1;
        int start = 0;

        // Every single character is a palindrome
        for (int i = 0; i < n; i++) {
            dp[i][i] = true;
        }

        // Check for palindromic substrings of length 2
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == s[i + 1]) {
                dp[i][i + 1] = true;
                start = i;
                maxLength = 2;
            }
        }

        // Check for lengths greater than 2
        for (int len = 3; len <= n; len++) {
            for (int i = 0; i < n - len + 1; i++) {
                int j = i + len - 1;
                
                if (s[i] == s[j] && dp[i + 1][j - 1]) {
                    dp[i][j] = true;
                    
                    if (len > maxLength) {
                        start = i;
                        maxLength = len;
                    }
                }
            }
        }

        return s.substr(start, maxLength);
    }
};

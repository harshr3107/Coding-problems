/*class Solution {
public:
    
    
    int getlongest(string s,int ind1,int ind2,vector<vector<int>>& dp)
    {
        
        
        if(ind2<ind1)
        {
            return 0;
        }
        
        if(ind2==ind1)
        {
            return 1;
        }
        
        
        if(dp[ind1][ind2]!=-1)
        {
            return dp[ind1][ind2];
        }
        
        if(s.at(ind1)==s.at(ind2))
        {
            dp[ind1][ind2]=2+getlongest(s,ind1+1,ind2-1,dp);
            return dp[ind1][ind2];
        }
        
        
        int moveright=0;
            if(ind1+1<=ind2)
            {
              moveright = getlongest(s,ind1+1,ind2,dp);
            }
        int moveleft=0;
        if(ind2-1>=ind1)
        {
           moveleft = getlongest(s,ind1,ind2-1,dp);
        }
        
        
        dp[ind1][ind2] = max(moveright,moveleft);
        
        return dp[ind1][ind2];
        
        
        
    }
    
    
    
    
    int longestPalindromeSubseq(string s) {
        
        int ind1 = 0;
        int ind2 = s.length()-1;
        
        vector<vector<int>> dp(s.length()+1,vector<int>(s.length()+1,-1));
        
        
        return getlongest(s,ind1,ind2,dp);
        
    }
};*/

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        // Base case: single characters are palindromic of length 1
        for (int i = 0; i < n; i++) {
            dp[i][i] = 1;
        }
        
        // Fill the table bottom-up
        for (int len = 2; len <= n; len++) {  // Length of substring
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;
                if (s[i] == s[j]) {
                    dp[i][j] = 2 + dp[i + 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }
        
        // The result is in dp[0][n - 1]
        return dp[0][n - 1];
    }
};

/*class Solution {
public:
    
    
    int getascii(string s,int ind)
    {
        int sum=0;
        
        for(int i=ind;i<s.length();i++)
        {
            sum+=int(s.at(i));
            
        }
        
        
        return sum;
        
    }
    
    
    
    
    int getminimum(string s1,string s2,int ind1,int ind2,vector<vector<int>>& dp)
    {
        
        if(ind1==s1.length() && ind2==s2.length())
        {
            return 0;
        }
        
        
        
        if (ind1 >= s1.length()) {
            return getascii(s2, ind2); // Remaining characters of s2
        }
        if (ind2 >= s2.length()) {
            return getascii(s1, ind1); // Remaining characters of s1
        }
        
        
        
        if(dp[ind1][ind2]!=-1)
        {
            return dp[ind1][ind2];
        }
        
        
        int no_opp=1e9+7;
        int d1 = 1e9+7;
        int d2 = 1e9+7;
        
        
        if(s1.at(ind1)==s2.at(ind2))
        {
            no_opp = getminimum(s1,s2,ind1+1,ind2+1,dp);
            dp[ind1][ind2]=no_opp;
            return dp[ind1][ind2];    
        }
        
        d1 = int(s1.at(ind1))+getminimum(s1,s2,ind1+1,ind2,dp);
        d2 = int(s2.at(ind2))+getminimum(s1,s2,ind1,ind2+1,dp);
        
        
        
        dp[ind1][ind2]=min(no_opp,min(d1,d2));
        
        return dp[ind1][ind2];
        
        
    }
    
    
    
    int minimumDeleteSum(string s1, string s2) {
        
        
        int ind1=0;
        int ind2=0;
        vector<vector<int>> dp(s1.length(),vector<int>(s2.length(),-1));
        
        return getminimum(s1,s2,ind1,ind2,dp);
      
        
        
        
        
        
        
    }
};*/

class Solution {
public:
    // Helper function to get ASCII value sum of a string
    int getascii(const string& s, int start) {
        int sum = 0;
        for (int i = start; i < s.length(); ++i) {
            sum += int(s[i]);
        }
        return sum;
    }
    
    // Recursive function with memoization
    int getminimum(string& s1, string& s2, int ind1, int ind2, vector<vector<int>>& dp) {
        if (ind1 == s1.length() && ind2 == s2.length()) {
            return 0;
        }
        if (ind1 >= s1.length()) {
            return getascii(s2, ind2); // Remaining characters of s2
        }
        if (ind2 >= s2.length()) {
            return getascii(s1, ind1); // Remaining characters of s1
        }
        if (dp[ind1][ind2] != -1) {
            return dp[ind1][ind2];
        }

        int no_opp = 1e9 + 7;
        int d1 = 1e9 + 7;
        int d2 = 1e9 + 7;

        if (s1[ind1] == s2[ind2]) {
            no_opp = getminimum(s1, s2, ind1 + 1, ind2 + 1, dp);
        } else {
            d1 = int(s1[ind1]) + getminimum(s1, s2, ind1 + 1, ind2, dp); // Delete from s1
            d2 = int(s2[ind2]) + getminimum(s1, s2, ind1, ind2 + 1, dp); // Delete from s2
        }

        dp[ind1][ind2] = min(no_opp, min(d1, d2));
        return dp[ind1][ind2];
    }

    int minimumDeleteSum(string s1, string s2) {
        vector<vector<int>> dp(s1.length() + 1, vector<int>(s2.length() + 1, -1));
        return getminimum(s1, s2, 0, 0, dp);
    }
};

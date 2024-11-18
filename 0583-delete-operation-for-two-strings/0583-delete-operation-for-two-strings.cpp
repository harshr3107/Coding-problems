class Solution {
public:
    int minDistance(string word1, string word2) {
        
        vector<vector<int>> dp(word1.length()+1,vector<int>(word2.length()+1,0));
        
        
        for(int i=1;i<=word1.length();i++)
        {
            for(int j=1;j<=word2.length();j++)
            {
                if(word1.at(i-1)==word2.at(j-1))
                {
                    dp[i][j]=1+dp[i-1][j-1];
                    continue;
                }
                
                int left = dp[i-1][j];
                int right = dp[i][j-1];
                
                dp[i][j]=max(left,right);
                
                
                
            }
            
        }
        
        
        
       int h = dp[word1.length()][word2.length()];
        
        return (word1.length()-h)+(word2.length()-h);
        
    }
};
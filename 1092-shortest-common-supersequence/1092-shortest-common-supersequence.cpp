class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        
        vector<vector<int>> dp(str1.length()+1,vector<int>(str2.length()+1,0));
        
        for(int i=1;i<=str1.length();i++)
        {
            
            for(int j=1;j<=str2.length();j++)
            {
                
                if(str1[i-1]==str2[j-1])
                {
                    dp[i][j]=1+dp[i-1][j-1];
                    continue;
                }
                
                int l = dp[i-1][j];
                int r = dp[i][j-1];
                
                dp[i][j]=max(l,r);
                
            }
            
        }
        
        
        cout<<dp[str1.length()][str2.length()]<<" ";
        
        
        //now let us print lcs 
        
        int i=str1.length();
        int j = str2.length();
        
        string str;
        
        while(i>0 && j>0)
        {
            
            if(str1.at(i-1)==str2.at(j-1))
            {
                str.push_back(str1.at(i-1));
                i--;
                j--;
                continue;
            }
            
            
            
            
            if(dp[i-1][j]>dp[i][j-1])
            {
                str.push_back(str1.at(i-1));
                i--;
                
            }else{
                
                str.push_back(str2.at(j-1));
                j--;
                
            }
            
            
            
        }
        
        while(i>0)
        {
            str.push_back(str1.at(i-1));
            i--;
            
        }
        
        while(j>0)
        {
            str.push_back(str2.at(j-1));
            j--;
            
        }
        
        
        
          reverse(str.begin(),str.end());
        
        
          return str;
        
        
    }
};
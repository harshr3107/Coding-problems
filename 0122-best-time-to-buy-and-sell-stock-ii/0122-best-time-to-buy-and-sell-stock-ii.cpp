/*class Solution {
public:
    
    
    int getprofit(vector<int>& prices,int i,int csi,vector<vector<int>>& dp)
    {
        
        if(i<0)
        {
            return 0;
        }
        
        if(dp[i][csi]!=-1)
        {
            return dp[i][csi];
        }
        
        
        int keep = getprofit(prices,i-1,csi,dp);
        
        
        int sell = 0;
        if(prices[i]<=prices[csi])
        {
            sell = (prices[csi]-prices[i])+getprofit(prices,i-1,i,dp);
        }else{
            
            sell = getprofit(prices,i-1,i,dp);
        }
        
        dp[i][csi]=max(keep,sell);
        return dp[i][csi];
        
        
    }
    
    
    
    
    
    int maxProfit(vector<int>& prices) {
        
        int i=prices.size()-2;
        int csi = i+1;
        int maxi = *max_element(prices.begin(),prices.end());
        
        
       vector<vector<int>> dp(prices.size()+1,vector<int>(prices.size()+1,-1));
        
        
        return getprofit(prices,i,csi,dp);
        
        
        //Tabulation
        
        vector<vector<int>> dp(prices.size()+1,vector<int>(prices.size()+1,0));
        int csi=0;
        
        
        for(int i=1;i<=prices.size();i++)
        {
            for(int j=1;j<=prices.size();j++)
            {
                
                int keep = dp[i-1][j];
        
        
                      int sell = 0;
                    if(prices[i]<=prices[j])
                     {
                        sell = (prices[j]-prices[i])+dp[i-1][i];
                      }else{
            
                          sell =dp[i-1][i];
                     }
        
                       dp[i][j]=max(keep,sell);
                
               }
            
            
        }
        
        
        return dp[prices.size()][prices.size()];
        
        
        
        
        
    }
};*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n <= 1) return 0;

        int maxProfit = 0;

        for (int i = 1; i < n; ++i) {
            if (prices[i] > prices[i - 1]) {
                maxProfit += prices[i] - prices[i - 1];
            }
        }

        return maxProfit;
    }
};

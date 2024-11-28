class Solution {
public:
    
    
    int getmax(vector<int>& prices,int index,bool buy,int fee,vector<vector<int>>& dp)
    {
        
        
        if(index==prices.size())
        {
            return 0;
        }
        
        
        if(dp[index][buy]!=-1)
        {
            return dp[index][buy];
        }
        
        int profit=0;
        
        if(buy)
        {
            int price1 = -prices[index]+getmax(prices,index+1,false,fee,dp);
            int price2 = getmax(prices,index+1,true,fee,dp);
            
            profit = max(price1,price2);
            
        }else{
            
            int price1 = prices[index]+getmax(prices,index+1,true,fee,dp);
            int price2 = getmax(prices,index+1,false,fee,dp);
            
            profit = max(price1-fee,price2);
            
            
        }
        
        dp[index][buy]=profit;
        return profit;
        
        
        
    }
    
    
    
    
    int maxProfit(vector<int>& prices, int fee) {
        
        
      vector<vector<int>> dp(prices.size()+1,vector<int>(2,-1));
        int index=0;
        bool buy=true;
        
        return getmax(prices,index,buy,fee,dp);
        
        
    }
};
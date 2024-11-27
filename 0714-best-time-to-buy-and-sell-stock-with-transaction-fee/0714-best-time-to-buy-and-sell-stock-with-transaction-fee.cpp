class Solution {
public:
    
    int getmax(vector<int>& prices,int index,int fee,bool buy,vector<vector<int>>& dp)
    {
        
        if(index>=prices.size())
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
            int price1 = -prices[index]+getmax(prices,index+1,fee,false,dp);
            int price2 = getmax(prices,index+1,fee,true,dp);
                
            profit = max(price1,price2);
            
            
        }else{
            
            int price1 = prices[index]+getmax(prices,index+1,fee,true,dp);
            int price2 = getmax(prices,index+1,fee,false,dp);
            
              profit = max(price1-fee,price2);
            
        }
        
        dp[index][buy]=profit;
        return profit;
        
        
    }
    
    
    
    
    
    
    
    int maxProfit(vector<int>& prices, int fee) {
        
        int index=0;
        bool buy = true;
        
        vector<vector<int>> dp(prices.size(),vector<int>(2,-1));
        
        
        return getmax(prices,index,fee,buy,dp);
        
        
    }
};
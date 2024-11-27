class Solution {
public:
    
    
    
    
    int getmaxprofit(vector<int>& prices,int index,bool buy,vector<vector<int>> dp)
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
            
            int price1 = -prices[index]+getmaxprofit(prices,index+1,false,dp);
            int price2 = getmaxprofit(prices,index+1,true,dp);
            
            profit = max(price1,price2);
            
            
        }else{
            
            int price1 = prices[index]+getmaxprofit(prices,index+2,true,dp);
            int price2 = getmaxprofit(prices,index+1,false,dp);
            
            profit = max(price1,price2);
            
        }
        
        dp[index][buy]=profit;
        return profit;
        
        
    }
    
    
    
    
    
    int maxProfit(vector<int>& prices) {
    
        
        /*int index=0;
        bool buy=true;
        vector<vector<int>> dp(prices.size(),vector<int>(2,-1));
        return getmaxprofit(prices,index,buy,dp);*/
        
        
        vector<vector<int>> dp(prices.size()+2,vector<int>(2,0));
        int n = prices.size();
        
        for(int index=n-1;index>=0;index--)
        {
            
            for(int buy=1;buy>=0;buy--)
            {
                 int profit=0;
        
        if(buy)
        {
            
            int price1 = -prices[index]+dp[index+1][0];
            int price2 = dp[index+1][1];
            
            profit = max(price1,price2);
            
            
        }else{
            
            
            
            int price1 = prices[index]+dp[index+2][1];
            int price2 = dp[index+1][0];
            
            profit = max(price1,price2);
            
        }
        
              dp[index][buy]=profit;
                
                
                
            }    


            
            
            
        }
        
        return dp[0][1];
        
        
        
    }
};
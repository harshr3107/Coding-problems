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
        
        
     /* vector<vector<int>> dp(prices.size()+1,vector<int>(2,-1));
        int index=0;
        bool buy=true;
        
        return getmax(prices,index,buy,fee,dp);*/
        
        
        //Tabulation
        
        /*
        vector<vector<int>> dp(prices.size()+1,vector<int>(3,0));
        
        int n = prices.size();
        
        for(int index=n-1;index>=0;index--)
        {
            
            for(int buy=0;buy<=1;buy++)
            {
                
                 int profit=0;
        
        if(buy)
        {
            int price1 = -prices[index]+dp[index+1][0];
            int price2 = dp[index+1][1];
            
            profit = max(price1,price2);
            
        }else{
            
            int price1 = prices[index]+dp[index+1][1];
            int price2 = dp[index+1][0];
            
            profit = max(price1-fee,price2);
            
            
        }
        
        dp[index][buy]=profit;
                
        }
            
            
        }
        
        
        return dp[0][1];
        
        */
        
        
        //optimize the problem
        
        vector<int> ahead(3,0);
        vector<int> current(3,0);
        
        int n = prices.size();
        
        for(int index=n-1;index>=0;index--)
        {
            
            for(int buy=0;buy<=1;buy++)
            {
                
                 int profit=0;
        
        if(buy)
        {
            int price1 = -prices[index]+ahead[0];
            int price2 = ahead[1];
            
            profit = max(price1,price2);
            
        }else{
            
            int price1 = prices[index]+ahead[1];
            int price2 = ahead[0];
            
            profit = max(price1-fee,price2);
            
            
        }
        
        current[buy]=profit;
                
        }
            
            ahead=current;
            
        }
        
        
        return current[1];
        
        
        
        
    }
};
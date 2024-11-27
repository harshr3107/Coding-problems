class Solution {
public:
    
    
    int getmax(vector<int>& prices,int index,bool buy,vector<vector<int>>& dp)
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
            //buy karle
            int price1 = -prices[index]+getmax(prices,index+1,false,dp);
            //ignore karle
            int price2 = getmax(prices,index+1,true,dp);
            
            profit = max(price1,price2);
            
            
        }else{
            
            //sell karle
            
            int price1 = prices[index]+getmax(prices,index+1,true,dp);
            
            //ignore karle
            
            int price2 = getmax(prices,index+1,false,dp);
            
            profit = max(price1,price2);
            
        }
        
        dp[index][buy]=profit;
        
        return dp[index][buy];
        
        
    }
    
    
    
    
    
    
    int maxProfit(vector<int>& prices) {
        
        /*vector<vector<int>> dp(prices.size()+1,vector<int>(2,-1));
        
        int index=0;
        int buy=0;
        
        return getmax(prices,0,true,dp);*/
        
        vector<vector<int>> dp(prices.size()+1,vector<int>(2,0));
        
        dp[prices.size()][1]=dp[prices.size()][0]=0;
        
        for(int index=prices.size()-1;index>=0;index--)
        {
            for(int buy=0;buy<=1;buy++)
            {
                
                 int profit=0;
        if(buy)
        {
            //buy karle
            int price1 = -prices[index]+dp[index+1][0];
            //ignore karle
            int price2 = dp[index+1][1];
            
            profit = max(price1,price2);
            
            
        }else{
            
            //sell karle
            
            int price1 = prices[index]+dp[index+1][1];
            
            //ignore karle
            
            int price2 =dp[index+1][0];
            
            profit = max(price1,price2);
            
        }
        
        dp[index][buy]=profit;
        
                
                
                
            }
            
        }
        
        
     return dp[0][1];   
        
    }
};



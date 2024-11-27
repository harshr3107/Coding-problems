class Solution {
public:
    
    
    //is ka sol ke pehle bset time 3 ki video dekh striver ki u will gwt it why i ttok k*2
    
    int getmax(vector<int>& prices,int index,int ctrans,int k,vector<vector<int>>& dp)
    {
        
        if(index==prices.size() || ctrans==k*2)
        {
            return 0;
        }
        
        if(dp[index][ctrans]!=-1)
        {
            return dp[index][ctrans];
        }
        
        int profit=0;
        
        if((ctrans&1)==0)
        {
           
            //buy
            
            int price1 = -prices[index]+getmax(prices,index+1,ctrans+1,k,dp);
            int price2 = getmax(prices,index+1,ctrans,k,dp);
            
            profit = max(price1,price2);
            
        }else{
            
            
            
            int price1 = prices[index]+getmax(prices,index+1,ctrans+1,k,dp);
            int price2 = getmax(prices,index+1,ctrans,k,dp);
            
            profit = max(price1,price2);
            
            
        }
        
        dp[index][ctrans]=profit;
        return profit;
        
        
    }
    
    
    
    
    
    
    int maxProfit(int k, vector<int>& prices) {
        
        /*int h = k*2;
        vector<vector<int>> dp(prices.size()+1,vector<int>(h+1,-1));
        int index=0;
        int ctrans=0;
        return getmax(prices,index,ctrans,k,dp);*/
        
        //
        int h = k*2;
        vector<vector<int>> dp(prices.size()+1,vector<int>(h+1,0));
        int n = prices.size();
        
        for(int index=n-1;index>=0;index--)
        {
            for(int ctrans=h-1;ctrans>=0;ctrans--)
            {
                int profit=0;
                
                if((ctrans&1)==0)
               {
           
            //buy
            
            int price1 = -prices[index]+dp[index+1][ctrans+1];
            int price2 = dp[index+1][ctrans];
            
            profit = max(price1,price2);
            
        }else{
            
            
            
            int price1 = prices[index]+dp[index+1][ctrans+1];
            int price2 = dp[index+1][ctrans];
            
            profit = max(price1,price2);
            
            
        }
        
        dp[index][ctrans]=profit;
                
                
                
            }
            
            
        }
        
        return dp[0][0];
        
        
    }
};
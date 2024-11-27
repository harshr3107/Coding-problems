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
        
        vector<vector<int>> dp(prices.size()+1,vector<int>(2,-1));
        
        int index=0;
        int buy=0;
        
        return getmax(prices,0,true,dp);
        
    }
};
/*
class Solution {
private:
    
    int solveMem(vector<int>& prices,int index,int buy,vector<vector<int>> &dp)
    {
             if(index==prices.size()) return 0;
             int profit=0;

             if(dp[index][buy]!=-1) return dp[index][buy];

             if(buy)
             {
                int buykaro=-prices[index]+solveMem(prices,index+1,0,dp);
                int skipkaro=0+solveMem(prices,index+1,1,dp);
                 profit=max(buykaro,skipkaro);
             }else
             {
                int sellkaro=+prices[index]+solveMem(prices,index,1,dp);
                int ignorekaro=0+solveMem(prices,index+1,0,dp);
                profit=max(sellkaro,ignorekaro);
             }
             return dp[index][buy]=profit;
    }  

 
public:
    int maxProfit(vector<int>& prices) {
         int n=prices.size();
         vector<vector<int>> dp(n+1,vector<int>(2,-1));
         return solveMem(prices,0,1,dp);
    }
};
*/
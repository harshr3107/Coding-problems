class Solution {
public:
    
    
    
    
    int getmax(vector<int>& prices,int index,bool buy,int ctrans,vector<vector<vector<int>>>& dp)
    {
        
        //cout<<index<<" "<<ctrans<<endl;
        
        
        if(index==prices.size() || ctrans==2)
        {
            return 0;
        }
        
        
            if(dp[index][buy][ctrans]!=-1)
        {
            return dp[index][buy][ctrans];
        }
        
        
        int profit=0;
        
        
        if(buy)
        {
            
            //check for transaction
            //if current transaction are greater than 2 then we need to sell p-revious
            
            
            
            
           
            int price1=-prices[index]+getmax(prices,index+1,false,ctrans,dp);
                
            int price2 = getmax(prices,index+1,true,ctrans,dp);
            
              profit = max(price1,price2);
            
            
        }else{
            
            
            int price1 = prices[index]+getmax(prices,index+1,true,ctrans+1,dp);
            int price2 = getmax(prices,index+1,false,ctrans,dp);
            
            
            profit=max(price1,price2);
            
            
        }
        
        dp[index][buy][ctrans]=profit;
       // cout<<"current profit is "<<profit<<endl;
        return profit;
        
        
        
    }
    
    
    
    
    
    int maxProfit(vector<int>& prices) {
        
    vector<vector<vector<int>>> dp(prices.size(),vector<vector<int>>(2,vector<int>(2,-1)));
        
        int index=0;
        int ctrans=0;
        return getmax(prices,index,true,ctrans,dp);
        
        
        
        
    }
};
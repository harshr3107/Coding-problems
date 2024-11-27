class Solution {
public:
    
    
    
   /* memonization 
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
    
    
    */
    
    
    int maxProfit(vector<int>& prices) {
        
   /* vector<vector<vector<int>>> dp(prices.size(),vector<vector<int>>(2,vector<int>(2,-1)));
        
        int index=0;
        int ctrans=0;
        return getmax(prices,index,true,ctrans,dp);*/
        
        
        vector<vector<vector<int>>> dp(prices.size()+1,vector<vector<int>>(2,vector<int>(3,0)));
        int n = prices.size();
        
        
        /*for(int i=0;i<n;i++)
        {
            for(int j=0;j<2;j++)
            {
                dp[i][j][2]=0;
                
            }
            
        }
        
        for(int i=0;i<2;i++)
        {
            for(int j=0;j<3;j++)
            {
               dp[n][i][j]=0; 
            }
        }*/
        
        
        
        for(int index=n-1;index>=0;index--)
        {
            for(int buy=0;buy<=1;buy++)
            {
                
                for(int ctrans=1;ctrans>=0;ctrans--)
                {
                    
                    int profit=0;
        
        
        if(buy)
        {
            
            //check for transaction
            //if current transaction are greater than 2 then we need to sell p-revious
            
            
            
            
           
            int price1=-prices[index]+dp[index+1][0][ctrans];
                
            int price2 = dp[index+1][1][ctrans];
            
              profit = max(price1,price2);
            
            
        }else{
            
            
            int price1 = prices[index]+dp[index+1][1][ctrans+1];
            int price2 = dp[index+1][0][ctrans];
            
            
            profit=max(price1,price2);
            
            
        }
        
        dp[index][buy][ctrans]=profit;
                    
                    
                    
                    
                    
                }   
                    
                
                
                
            }
            
            
            
            
        }
        
        return dp[0][1][0];
        
    }
};
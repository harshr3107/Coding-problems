class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int maxi=0;
        int minprice=prices[0];
        
        for(int i=1;i<prices.size();i++)
        {
            maxi = max(maxi,prices[i]-minprice);
            minprice=min(minprice,prices[i]);
            
        }
        
        return maxi;
        
        
        
        
    }
};
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        /*multiset<int> s;
        
        for(int i=1;i<prices.size();i++)
        {
            s.insert(prices[i]);
        }
        
        int maxi=0;
        
        for(int j=0;j<prices.size()-1;j++)
        {
            maxi = max(maxi,*s.rbegin()-prices[j]);
            s.erase(s.find(prices[j+1]));
            
        }*/
        
        int maxi=0;
        
        int minprice=prices[0];
        
        for(int j=1;j<prices.size();j++)
        {
            
           maxi = max(maxi,prices[j]-minprice);
            minprice= min(minprice,prices[j]);
           
            
        }
        
        
        return maxi;
        
        
    }
};
class Solution {
public:
    
    void getnextsmallest(vector<int>& prices,vector<int>& nextsmallest)
    {
        
        stack<int> st;
        st.push(-1);
        
        int i=prices.size()-1;
        nextsmallest[i]=-1;
        st.push(i);
        i--;
        
        while(i>=0)
        {
            
        
        while(st.top()!=-1 && prices[st.top()]>prices[i])
        {
            
            st.pop();
            
        }
            
            nextsmallest[i]=st.top();
            st.push(i);
            
         
            
            i--;
            
        }
        
        
        
        
    }
    
    
    
    
    vector<int> finalPrices(vector<int>& prices) {
        
        vector<int> nextsmallest(prices.size(),-1);
        
        getnextsmallest(prices,nextsmallest);
        
        vector<int> ans(prices);
        
        
        for(int i=0;i<nextsmallest.size();i++)
        {
            
            if(nextsmallest[i]!=-1)
            {
                ans[i] = (prices[i]-prices[nextsmallest[i]]);
            }
        }
        
        return ans;
        
        
        
        
    }
};
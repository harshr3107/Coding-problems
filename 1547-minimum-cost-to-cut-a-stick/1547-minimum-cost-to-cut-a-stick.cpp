class Solution {
public:

    
    int getmincost(vector<int>& cuts,int start,int end,vector<vector<int>>& dp)
    {
       
        
        if(start>end)
        {
            return 0;
        }
        
        if(dp[start][end]!=-1)
        {
            return dp[start][end];
        }
        
        
       
        int mini = 1e9+7;
        
        
        
        for(int i=start;i<=end;i++)
        {
            int a = cuts[end+1]-cuts[start-1]+getmincost(cuts,start,i-1,dp)+getmincost(cuts,i+1,end,dp);
            
            mini = min(mini,a);
        }
        
        
        dp[start][end]=mini;
        return mini;
        
        
        
        
        
        
    }
    
    
    
    
    
    
    
    int minCost(int n, vector<int>& cuts) {
        
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        
        vector<vector<int>> dp(cuts.size()+2,vector<int>(cuts.size()+2,-1));
        
        int mini=1e9+7;
        int start=1;
        int end=cuts.size()-2;
        
     
        
         return getmincost(cuts,start,end,dp);
            
        
        
        
        
        
        
        
        
        
    }
};
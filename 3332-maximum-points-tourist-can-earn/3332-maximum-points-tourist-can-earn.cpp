class Solution {
public:
    
    
    
    
    int getmax(vector<vector<int>>& stay,vector<vector<int>>& travel,int k,int n,int curcity,vector<vector<int>>& dp,int cday)
    {
        
        //cout<<"the curcity is "<<curcity<<endl;
       if(cday == k) {
           
            return 0; // Potential out-of-bounds access
       }

        
        
    
        
               // cout<<"value of curcity is "<<curcity<<" ans "<<"the day is "<<k<<endl;

        
        if(dp[curcity][cday]!=-1)
        {
            return dp[curcity][cday];
        }
        
        
        
        //welecting to stay
        int stays = getmax(stay,travel,k,n,curcity,dp,cday+1)+stay[cday][curcity];
        //move to other destination
        int notstay = INT_MIN;
        for(int i=0;i<n;i++)
        {
            if(i!=curcity)
            {
               // notstay = max(notstay,getmax(stay,travel,k,n,i,dp,cday+1)+travel[curcity][cday]);
                
                notstay = max(notstay, travel[curcity][i] + getmax(stay, travel, k, n, i, dp, cday + 1));

            }
        }
        
        dp[curcity][cday]=max(stays,notstay);
        
        return dp[curcity][cday];
        
        
        
    }
    
    
    
    int maxScore(int n, int k, vector<vector<int>>& stay, vector<vector<int>>& travel) {
        
      vector<vector<int>> dp(n+1,vector<int>(k+1,-1));
        
        int ans = INT_MIN;
        int cday=0;
        
        for(int i=0;i<n;i++)
        {
           ans = max(ans,getmax(stay,travel,k,n,i,dp,cday));    
            //cout<<"the ans is "<<ans<<endl;
        }
        
        return ans;
            
        
        
    }
};
/*

class Solution {
public:
    int getmax(vector<vector<int>>& stay, vector<vector<int>>& travel, int k, int n, int curcity, vector<vector<int>>& dp, int cday) {
        // Base case: if we've reached the number of days
        if (cday == k) {
            return 0; // No points can be earned after the last day
        }

        // Check if we have already computed the answer for this state
        if (dp[curcity][cday] != -1) {
            return dp[curcity][cday];
        }

        // Option 1: Stay in the current city
        int stays = stay[cday][curcity] + getmax(stay, travel, k, n, curcity, dp, cday + 1);

        // Option 2: Move to another city
        int notstay = INT_MIN;
        for (int i = 0; i < n; i++) {
            if (i != curcity) {
                notstay = max(notstay, travel[curcity][i] + getmax(stay, travel, k, n, i, dp, cday + 1));
            }
        }

        // Store and return the maximum score
        dp[curcity][cday] = max(stays, notstay);
        return dp[curcity][cday];
    }

    int maxScore(int n, int k, vector<vector<int>>& stay, vector<vector<int>>& travel) {
        // Initialize the DP table with size n x (k + 1)
        vector<vector<int>> dp(n, vector<int>(k, -1));

        int ans = INT_MIN;

        // Evaluate starting from each city
        for (int i = 0; i < n; i++) {
            ans = max(ans, getmax(stay, travel, k, n, i, dp, 0));
        }

        return ans;
    }
};
*/


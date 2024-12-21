/*class Solution {
public:
    
    
    
    int getmin(vector<int>& days,int i,int tavl,vector<int>& costs,vector<int>& dp)
    {
        
        
       if(i==days.size())
       {
           
           return 0;
       }
        
        if(dp[i]!=-1)
        {
            return dp[i];
        }
        
        
        int no_ticket=INT_MAX;
        
        if(tavl>=days[i])
        {
               no_ticket = getmin(days,i+1,tavl,costs,dp);
        }
           
        
        int one_day = costs[0]+getmin(days,i+1,days[i],costs,dp);
        int seven_day = costs[1]+getmin(days,i+1,days[i]+6,costs,dp);
        int thirty_day = costs[2]+getmin(days,i+1,days[i]+29,costs,dp);
        
        
        dp[i] = min(min(one_day,no_ticket),min(seven_day,thirty_day));
        
        return dp[i];
        
       
        
        
        
        
        
    }
   
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {
       
           int i=0;
           int tavl=0;
           vector<int> dp(days.size()+1,-1);
           return getmin(days,i,tavl,costs,dp);
        
        
    }
};*/

class Solution {
public:
    int getmin(vector<int>& days, int i, int tavl, vector<int>& costs, vector<vector<int>>& dp) {
        if (i == days.size()) {
            return 0; // All days covered
        }

        if (dp[i][tavl] != -1) {
            return dp[i][tavl];
        }

        int no_ticket = INT_MAX;

        // If current day is covered by a previous ticket, skip buying
        if (tavl >= days[i]) {
            no_ticket = getmin(days, i + 1, tavl, costs, dp);
        }

        // Buy a 1-day ticket
        int one_day = costs[0] + getmin(days, i + 1, days[i], costs, dp);

        // Buy a 7-day ticket
        int seven_day = costs[1] + getmin(days, i + 1, days[i] + 6, costs, dp);

        // Buy a 30-day ticket
        int thirty_day = costs[2] + getmin(days, i + 1, days[i] + 29, costs, dp);

        // Take the minimum of all options
        dp[i][tavl] = min({no_ticket, one_day, seven_day, thirty_day});
        return dp[i][tavl];
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int max_day = days.back(); // Maximum day value
        vector<vector<int>> dp(days.size(), vector<int>(max_day + 30, -1)); // 2D DP array
        return getmin(days, 0, 0, costs, dp); // Start from day 0 with no coverage
    }
};

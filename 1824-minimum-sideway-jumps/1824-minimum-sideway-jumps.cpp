
class Solution {
public:
    int minjump(vector<int>& obstacles, int ind, int lane, vector<vector<int>>& dp) {
        // Base case: If we reach the last position, no jumps are needed
        if (ind == obstacles.size() - 1) {
            return 0;
        }
        
         //cout<<"i am here at "<<ind<<" in the lane "<<lane<<endl;

        // If already computed, return the stored result
        if (dp[lane][ind] != -1) {
            return dp[lane][ind];
        }

        int curlane = 1e9; // Cost of continuing in the current lane
        int switchLane = 1e9; // Cost of switching lanes

        // If the next position is not blocked in the current lane, continue in the same lane
        if (obstacles[ind + 1] != lane) {
            curlane = minjump(obstacles, ind + 1, lane, dp);
        }else{

        // Check for valid side jumps
        for (int newLane = 1; newLane <= 3; newLane++) {
            // Skip the current lane and ensure the new lane is not blocked
            if (newLane != lane && obstacles[ind] != newLane) {
                switchLane = min(switchLane, 1 + minjump(obstacles, ind, newLane, dp));
            }
        }
            
        }

        // Store the result and return the minimum of continuing or switching lanes
        dp[lane][ind] = min(curlane, switchLane);
        return dp[lane][ind];
    }

    int minSideJumps(vector<int>& obstacles) {
        int n = obstacles.size();
        vector<vector<int>> dp(4, vector<int>(n+1, -1)); // DP table for 3 lanes and indices 0 to n-1
        return minjump(obstacles, 0, 2, dp); // Start at lane 2, index 0
    }
};

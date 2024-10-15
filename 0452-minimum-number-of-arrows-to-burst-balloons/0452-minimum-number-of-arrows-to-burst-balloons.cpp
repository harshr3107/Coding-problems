class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.empty()) return 0;

        // Sort intervals by their end times
        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];  // Sort by end time
        });

        int arrows = 1;  // Start with one arrow
        int lastEnd = points[0][1];  // Set the end time of the first balloon
        
        // Loop through the intervals
        for (int i = 1; i < points.size(); ++i) {
            // If the current balloon starts after the last one ended, we need a new arrow
            if (points[i][0] > lastEnd) {
                arrows++;  // Shoot a new arrow
                lastEnd = points[i][1];  // Update the end time to the current balloon's end
            }
        }

        return arrows;  // Return the total number of arrows needed
    }
};

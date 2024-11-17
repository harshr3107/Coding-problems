/*class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        
        
        
        
        for(int i=0;i<queries.size();i++)
        {
            
            
            for(int j=queries[i][0];j<=queries[i][1];j++)
            {
                if(nums[j]>0)
                {
                    nums[j]--;
                }
                
            }
            
        }
        
        
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]!=0)
            {
                return false;
            }
        }
        
        return true;
            
            
        
    }
};*/
class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> diff(n + 1, 0); // Difference array for efficient range updates

        // Process each query
        for (const auto& query : queries) {
            int l = query[0];
            int r = query[1];

            // Apply range decrement using the difference array
            diff[l] -= 1;
            if (r + 1 < n) {
                diff[r + 1] += 1;
            }
        }

        // Apply the cumulative difference to the array and check
        int decrement = 0;
        for (int i = 0; i < n; ++i) {
            decrement += diff[i]; // Accumulate the decrement
            nums[i] += decrement; // Apply decrement to nums

            // Check if any element remains positive
            if (nums[i] > 0) {
                return false;
            }
        }

        return true;
    }
};

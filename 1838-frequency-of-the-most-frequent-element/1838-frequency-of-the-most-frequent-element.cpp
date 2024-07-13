/*class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        
        
        
        
        int j;
        sort(nums.begin(),nums.end());
        int i=nums.size()-1;
        int ans=1;
        int maxi = INT_MIN;
        int count;
        int m;
        
        while(i>=ans)
        {
            
            maxi=nums[i];
            j=i-1;
            count=1;
            m=0;
            
          while(j>=0 && m<=k)
          {
               m+=(maxi-nums[j]);
               count++;
               j--;
              
          }   
         
            
            if(j==-1 && m<=k)
            {
                count=count;
            }else{
                
               count--;
                
            }
            
            ans=max(ans,count);
            i--;
            
        }
            
            return ans;
    }
};*/



/*class Solution {
public:
    int maxFrequency(vector<int>& A, int k) {
        sort(begin(A), end(A));
        long i = 0, N = A.size(), ans = 1, sum = 0;
        for (int j = 0; j < N; ++j) {
            sum += A[j];
            while ((j - i + 1) * A[j] - sum > k) sum -= A[i++];
            ans = max(ans, j - i + 1);
        }
        return ans;
    }
};*/

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int maxFrequency = 0; // Initialize the maximum frequency
        long currentSum = 0; // Initialize the current sum of the subarray elements

        std::sort(nums.begin(), nums.end()); // Sort the array in ascending order

        for (int left = 0, right = 0; right < nums.size(); ++right) {
            currentSum += nums[right]; // Include the current element in the subarray sum

            // Check if the current subarray violates the condition (sum + k < nums[right] * length)
            while (currentSum + k < static_cast<long>(nums[right]) * (right - left + 1)) {
                currentSum -= nums[left]; // Adjust the subarray sum by removing the leftmost element
                left++; // Move the left pointer to the right
            }

            // Update the maximum frequency based on the current subarray length
            maxFrequency = std::max(maxFrequency, right - left + 1);
        }

        return maxFrequency;
    }
};

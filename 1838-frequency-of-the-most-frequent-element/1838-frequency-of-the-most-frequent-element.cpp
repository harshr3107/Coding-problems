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



class Solution {
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
};
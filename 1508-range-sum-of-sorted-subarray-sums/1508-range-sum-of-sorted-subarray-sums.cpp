class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        
        vector<int> prefixsum(nums.size());
        vector<int> v;
        
        int mod = 1e9+7;
        int  sum=0;
        
        for(int i=0;i<nums.size();i++)
        {
            sum=sum+nums[i];
            prefixsum[i]=sum;
            v.push_back(sum);
            
        }
        
        
        
        int i=0;
        int j=1;

        while(j<nums.size())
        {
            i=j-1;
            
            while(i>=0)
            {
                v.push_back(prefixsum[j]-prefixsum[i]);
                i--;
            }
            
            j++;
        }
        
        sort(v.begin(),v.end());
        
        sum=0;
        
        for(int i=left-1;i<right;i++)
        {
            sum=(sum+v[i])%mod;
        }
        
        
        
        return sum;
        
    }
};
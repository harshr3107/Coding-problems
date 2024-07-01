class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        map<int,int> m;
        int sum=0;
        int ans=0;
        m[sum]++;
        
        for(int i=0;i<nums.size();i++)
        {
            sum=sum+nums[i];
            int element = sum-k;
            if(m.find(element)!=m.end())
            {
                ans+=m[element];
            }
            m[sum]++;
        }
        
        return ans;
        
    }
};
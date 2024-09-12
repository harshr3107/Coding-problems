class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        
        set<int> s;
        
        for(int i=0;i<nums.size();i++)
        {
            s.insert(nums[i]);
        }
        
        int a = *s.rbegin();
        
        for(int i=1;i<=a;i++)
        {
            if(!s.count(i))
            {
                return i;
            }
        }
        
        if(a<0)
        {
            return 1;
        }
        
        return a+1;
        
        
    }
};
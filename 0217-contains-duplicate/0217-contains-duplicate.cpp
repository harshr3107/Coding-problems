class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        
        map<int,int> mp;
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
            if(mp[nums[i]]==2)
            {
                return true;
            }
        }
        
        
        return false;
        
    }
};
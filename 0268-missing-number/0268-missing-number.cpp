class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        vector<int> count(nums.size()+1);
        
        for(int i=0;i<nums.size();i++)
        {
            count[nums[i]]++;
        }
      
        
        
        vector<int>::iterator it = find(count.begin(),count.end(),0);
        
        int a=it-count.begin();
        
        return a;
        
    }
};
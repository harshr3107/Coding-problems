class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        priority_queue<int> maxheap;
        
        for(int i=0;i<nums.size();i++)
        {
            maxheap.push(nums[i]);
        }
        
        
        int i=1;
        while(i<k)
        {
            maxheap.pop();
            i++;
        }
        
        
        return maxheap.top();
        
        
    }
};
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        
        int low=0;
        int high=numbers.size()-1;
        int mid=0;
        vector<int> ans;
        
        
        while(high>low)
        {
            if(numbers[low]+numbers[high]==target)
            {
                ans.push_back(low+1);
                ans.push_back(high+1);
                return ans;
            }else if(numbers[low]+numbers[high]>target)
            {
                high--;
            }else{
                low++;
            }
            
        }
        
        return ans;
        
        
    }
};
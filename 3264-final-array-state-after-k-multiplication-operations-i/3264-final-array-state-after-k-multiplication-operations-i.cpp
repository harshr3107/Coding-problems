class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        
        for(int i=0;i<k;i++)
        {
            int mini = *min_element(nums.begin(),nums.end());
            //cout<<"value of mini is "<<mini<<endl;
            int temp = mini;
            mini=mini*multiplier;
            //cout<<"new value of mini is "<<mini<<endl;
            
            int h = find(nums.begin(),nums.end(),temp)-nums.begin();
            nums[h]=mini;
            //cout<<"value of h is "<<h<<endl;
            
        }
        
        
        return nums;
        
    }
};
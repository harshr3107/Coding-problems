class Solution {
    
public:
    
    
    
  void merge(vector<int> &nums, int low, int mid, int high){

    int l=low;
    int r=mid+1;

    vector<int> ans;

     while(l<=mid && r<=high){
        if(nums[l]<=nums[r]){
            ans.push_back(nums[l]);
            l++;
        }
        else
        {
            ans.push_back(nums[r]);
            r++;
        }
        }

    while(l<=mid){
        ans.push_back(nums[l]);
        l++;
    }

    while(r<=high){
        ans.push_back(nums[r]);
        r++;
    }

    for(int i=low; i<=high; i++)
    nums[i]=ans[i-low];
}
    
    
    
    
    void mergesort(vector<int>& nums,int low,int high)
    {
        
        if(high>low)
        {
        int mid = (low+high)/2;
        mergesort(nums,low,mid);
        mergesort(nums,mid+1,high);
    
        merge(nums,low,mid,high);
            
        }
    }
    
    
    
    
    vector<int> sortArray(vector<int>& nums) {
        
        mergesort(nums,0,nums.size()-1);
        
        return nums;
        
        
        
    }
};
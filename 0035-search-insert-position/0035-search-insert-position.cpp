class Solution {
public:
    int searchInsert(vector<int>& arr, int target) {
        
        int low=0;
        int high=arr.size()-1;
        int mid=0;
        int ans=0;
        
        while(high>=low)
        {
            mid=low+(high-low)/2;
            
            if(arr[mid]==target)
            {
                ans=mid;
                return ans;
                
            }else if(arr[mid]>target)
            {
                high=mid-1;
                ans=high;
            }else{
                low=mid+1;
                ans=low;
            }
            
        }
        
        if(ans<0)
        {
            ans++;
            return ans;
        }
        
        if(ans==arr.size())
        {
            return ans;
        }
        
        cout<<"value of ans is "<<ans<<endl;
        
        if(arr[ans]<target)
        {
            ans++;
        }
        
        return ans;
        
        
    }
};
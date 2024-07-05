class Solution {
public:
    int searchInsert(vector<int>& arr, int target) {
        
        int low=0;
        int high=arr.size()-1;
        int mid=0;
       
        
        while(high>=low)
        {
            mid=low+(high-low)/2;
            
            if(arr[mid]==target)
            {
                
                return mid;
                
            }else if(arr[mid]>target)
            {
                high=mid-1;
                
            }else{
                low=mid+1;
                
            }
            
        }
        
        /*if(ans<0)
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
        */
        return low;
        
        
    }
};
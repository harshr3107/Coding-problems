class Solution {
public:
    void sortColors(vector<int>& arr) {
        
        int low=0;
        int high=arr.size()-1;
        int mid=0;
        
        
        while(high>=mid)
        {
            
            if(arr[mid]==0)
            {
                int temp = arr[low];
                arr[low] = arr[mid];
                arr[mid] = temp;
                low++;
                mid++;
                
            }else if(arr[mid]==2)
            {
                int temp = arr[mid];
                arr[mid]=arr[high];
                arr[high]=temp;
                high--;
                
            }else {
                
                mid++;
            }
            
            
        }
        
    }
};
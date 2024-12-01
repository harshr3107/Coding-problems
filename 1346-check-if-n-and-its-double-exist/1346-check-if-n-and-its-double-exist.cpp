class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        
       int i=0;
       int j=arr.size()-1;
        
        sort(arr.begin(),arr.end());
        
        while(i<arr.size())
        {
            auto it = find(arr.begin(),arr.end(),arr[i]*2);
            
            if(it!=arr.end() && (it-arr.begin())!=i)
            {
                return true;
            }
            
            i++;
            
        }
        
        
        return false;
        
        
        
    }
};
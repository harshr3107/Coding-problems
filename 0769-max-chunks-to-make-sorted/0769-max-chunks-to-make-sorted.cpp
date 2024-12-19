class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        
        int mini=INT_MAX;
        int maxi=INT_MIN;
        
        int start=0;
        
        int chunk=0;
        
        for(int i=0;i<arr.size();i++)
        {
            mini = min(mini,arr[i]);
            maxi = max(maxi,arr[i]);
            
            if(mini==start && maxi==i)
            {
                chunk++;
                start=maxi+1;
                mini=INT_MAX;
                maxi=INT_MIN;
            }
            
        }
        
        
        return chunk;
        
    }
};
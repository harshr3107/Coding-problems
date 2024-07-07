class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        
        int max=INT_MIN;
        
        for(int i=0;i<arr.size();i++)
        {
            if(max<arr[i])
            {
                max=arr[i];
            }
        }
        
        
        vector<int> count(max+1);
        
        for(int i=0;i<arr.size();i++)
        {
            count[arr[i]]++;
        }
        
        int h=0;
        
        for(int i=1;i<=max;i++)
        {
           // cout<<"value of count is "<<i<<" "<<count[i]<<endl;
            
            if(count[i]==0)
            {
                h++;
                if(h==k)
                {
                    return i;
                }
            }
            
        }
        
        
        
        
        return max+(k-h);
        
        
        
        
    }
};
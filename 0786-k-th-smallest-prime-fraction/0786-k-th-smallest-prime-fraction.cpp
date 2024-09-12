class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        
        priority_queue<pair<float,vector<int>>> maxheap;
        vector<int> v;
        
        for(int i=0;i<arr.size()-1;i++)
        {
            for(int j=i+1;j<arr.size();j++)
            {
                float a = float(arr[i])/arr[j];
                v.push_back(arr[i]);
                v.push_back(arr[j]);
                //cout<<"value of a is "<<a<<endl;
                
            if(maxheap.size()<k)
            {
                
                maxheap.push(make_pair(a,v));
                
            }else{
                
                if(maxheap.top().first>a)
                {
                    maxheap.pop();
                    maxheap.push(make_pair(a,v));
                }
                
                
            }
                
                
                v.clear();
            }
        }
        
        
        return maxheap.top().second;
        
    }
};
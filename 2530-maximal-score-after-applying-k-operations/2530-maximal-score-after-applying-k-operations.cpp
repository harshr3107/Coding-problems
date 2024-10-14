class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        
        priority_queue<long long> maxheap;
        
        for(int i=0;i<nums.size();i++)
        {
            maxheap.push(nums[i]);
        }
        
        
        
        int i=0;
        long long ans=0;
        
        while(i<k)
        {
            
            double h = maxheap.top();
            //cout<<"here val for h is "<<h<<endl;
            ans=ans+static_cast<long long>(h);
            maxheap.pop();
            
            maxheap.push(ceil(h/3));
            
            i++;
            
            
        }
        
        
        
        
        return ans;
        
        
        
        
        
    }
};
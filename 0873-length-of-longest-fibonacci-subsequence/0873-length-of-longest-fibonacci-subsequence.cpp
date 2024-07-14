class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        
        map<int,int> mp;
        
        for(int i=0;i<arr.size();i++)
        {
            mp[arr[i]]++;
        }
        
        
        int low=0;
        int high;
        int cursum;
        int prev;
        int ans=1;
        int temp;
        int lastind;
        int a;
        
        while(low<arr.size())
        {
            
            high=low+1;
            prev=arr[low];
            
            
            while(high<arr.size())
            {
                prev=arr[low];
                lastind=arr[high];
                cursum=prev+lastind;
                a=2;
                
                while(mp.find(cursum)!=mp.end())
                {
                    temp=cursum;
                    a++;
                    cursum=cursum+lastind;
                    lastind=temp;
            
                    
                }
                
                ans=max(ans,a);
                high++;
                
            }
            
            
            low++;
            
        }
        
        if(ans<=2)
        {
            return 0;
        }
        
        
        return ans;
        
    }
};
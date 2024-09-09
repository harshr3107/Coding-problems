class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        
        priority_queue<pair<int,pair<int,int>>> maxheap;
        
        
        for(int i=0;i<nums1.size();i++)
        {
            for(int j=0;j<nums2.size();j++)
            {
                if(maxheap.size()<k)
                {
                    maxheap.push(make_pair(nums1[i]+nums2[j],make_pair(nums1[i],nums2[j])));
                }else if(maxheap.top().first>(nums1[i]+nums2[j]))
                {
                        maxheap.pop();
                        maxheap.push(make_pair(nums1[i]+nums2[j],make_pair(nums1[i],nums2[j])));
                        
                }else{
                    
                    break;
                }
                    
                
                
            }
        }
        
        vector<vector<int>> ans(k);
        vector<int> v;
        int i=k-1;
        
        while(!maxheap.empty())
        {
            //cout<<maxheap.top().first<<" "<<maxheap.top().second.first<<" "<<maxheap.top().second.second<<endl;
            v.push_back(maxheap.top().second.first);
            v.push_back(maxheap.top().second.second);
            ans[i]=v;
            v.clear();
            i--;
            maxheap.pop();
        }
        
        return ans;
        
        
    }
};
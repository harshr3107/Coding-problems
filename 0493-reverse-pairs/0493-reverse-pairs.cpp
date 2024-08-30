/*class Solution {
public:
    int reversePairs(vector<int>& nums) {
        
        
        multiset<long long> s;
        
        for(int i=1;i<nums.size();i++)
        {
            
            s.insert(nums[i]*(long long)2);
        }
        
        
        multiset<long long>:: iterator it; 
        int ans=0;
        int pos=0;
        
        for(int j=0;j<nums.size()-1;j++)
        {
            it = s.lower_bound(nums[j]);
            //cout<<"lower bound for "<<nums[j]<<" is "<<*it;
            pos = distance(s.begin(),it);
            ans+=pos;
           // cout<<"the pos is "<<pos<<endl;
            
            s.erase(s.find(nums[j+1]*(long long)2));
            
            
            
           
        }
        
        
        
        return ans;
        
    }
};
*/

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using ll = long long;
typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag,
             tree_order_statistics_node_update>
    orderedMultiset;
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        orderedMultiset st;
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += st.size() - st.order_of_key((2 * 1ll * nums[i]) + 1);
            st.insert(nums[i]);
        }
        return ans;
    }
};


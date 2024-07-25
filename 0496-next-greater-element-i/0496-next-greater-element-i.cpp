class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        stack<int> st;
        vector<int> ans;
        ans.push_back(-1);
        st.push(-1);
        st.push(nums2[nums2.size()-1]);
        
        
        
        for(int i=nums2.size()-2;i>=0;i--)
        {
            
            if(nums2[i]<st.top())
            {
                ans.push_back(st.top());
                st.push(nums2[i]);
            }else{
                
                while(nums2[i]>=st.top() && st.top()!=-1)
                {
                    st.pop();
                }
                
                ans.push_back(st.top());
                st.push(nums2[i]);
                
                
                
            }
            
            
        }
        
        map<int,int> m;
        
        for(int i=0;i<nums2.size();i++)
        {
            m[nums2[i]]=i;
        }
        
        
        reverse(ans.begin(),ans.end());
        
        vector<int> answer;
        
        for(int i=0;i<nums1.size();i++)
        {
            answer.push_back(ans[m[nums1[i]]]);
        }
        
        
        
        
       /* for(int i=0;i<ans.size();i++)
        {
            ans[i] = m[ans[i]];
            
        }*/
        
        
        
        return answer;
        
        
    }
};
/*class Solution {
public:
    
    void getprevhighest(stack<int> st,vector<int>& prevhighest,vector<int> height)
    {
        
        for(int i=0;i<height.size();i++)
        {
            while(st.top()!=-1 && st.top()<height[i])
            {
                st.pop();
            }
            
            prevhighest[i]=st.top();
            st.push(height[i]);
            
        }
        
        
    }
    
    void getnexthighest(stack<int> st,vector<int>& nexthighest,vector<int> height)
    {
        
        for(int j=height.size()-1;j>=0;j--)
        {
            while(st.top()!=-1 && st.top()<height[j])
            {
                st.pop();
            }
            
            nexthighest[j]=st.top();
            st.push(height[j]);
            
        }
        
        
        
        
    }
    
    
    void display(vector<int> height)
    {
        for(int i=0;i<height.size();i++)
        {
            cout<<height[i]<<" ";
        }
        cout<<endl;
    }
    
    
    
    
    
    int trap(vector<int>& height) {
        
        stack<int> st1;
        vector<int> prevhighest(height.size());
        st1.push(-1);
        st1.push(height[0]);
        
        
        stack<int> st2;
        st2.push(-1);
        st2.push(height[height.size()-1]);
        vector<int> nexthighest(height.size());
        
        
        
        getprevhighest(st1,prevhighest,height);
        getnexthighest(st2,nexthighest,height);
        
        display(prevhighest);
        display(nexthighest);
        
        int area=0;
        
        
        for(int i=0;i<height.size();i++)
        {
            if(prevhighest[i]!=-1 && nexthighest[i]!=-1)
            {
               
              area+=min(prevhighest[i],nexthighest[i]) -height[i];
                
            }
        
        
        }
        
     
        
        
        
        return area;
        
        
        
        
        
    }
};

*/



class Solution {
private:
    vector<int> nextLargerLeft(vector<int>& nums){
        int n = nums.size();
        vector<int> ans(n);
        stack<int> st;
        st.push(-1);
        for (int i = 0; i < n; i++){
            while (st.top() != -1 && nums[i] >= nums[st.top()]){
                st.pop();
            }
            ans[i] = st.top();
            if (st.top() != -1 && nums[st.top()] > nums[i]){
                // dont append
            }
            else{
                st.push(i);
            }
        }
        return ans;
    }

    vector<int> nextLargerRight(vector<int>& nums){
        int n = nums.size();
        vector<int> ans(n);
        stack<int> st;
        st.push(-1);
        for (int i = n-1; i >= 0; i--){
            while (st.top() != -1 && nums[i] >= nums[st.top()]){
                st.pop();
            }
            ans[i] = st.top();
            if (st.top() != -1 && nums[st.top()] > nums[i]){
                // dont append
            }
            else{
                st.push(i);
            }
        }
        return ans;
    }

public:
    int trap(vector<int>& height) {
        vector<int> prev = nextLargerLeft(height);
        vector<int> next = nextLargerRight(height);
        int n = height.size();
        int ans = 0;

        for (int i = 0 ; i< n ; i++){
            if (prev[i] != -1 && next[i] != -1){
                ans += min(height[prev[i]], height[next[i]]) - height[i];
            }
        }
        return ans;
    }
};


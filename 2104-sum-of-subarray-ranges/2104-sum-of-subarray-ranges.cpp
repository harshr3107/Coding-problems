class Solution {
public:
    
    void getnextsmallest(vector<int> nums,vector<int>& nextsmallest)
    {
        stack<int> st;
        st.push(-1);
        
        
        for(int i=nums.size()-1;i>=0;i--)
        {
            while(st.top()!=-1 && nums[st.top()]>=nums[i])
            {
                st.pop();
            }
            
            nextsmallest[i]=st.top();
            st.push(i);
            
        }
        
    }
    
    void getprevsmallest(vector<int> nums,vector<int>& prevsmallest)
    {
         stack<int> st;
         st.push(-1);
        
        
         
        for(int i=0;i<nums.size();i++)
        {
            while(st.top()!=-1 && nums[st.top()]>nums[i])
            {
                st.pop();
            }
            
            prevsmallest[i]=st.top();
            st.push(i);
            
        }
        
    }
    
    void getnextlargest(vector<int> nums,vector<int>& nextlargest)
    {
         stack<int> st;
         st.push(-1);
        
        
         
        for(int i=nums.size()-1;i>=0;i--)
        {
            while(st.top()!=-1 && nums[st.top()]<=nums[i])
            {
                st.pop();
            }
            
            nextlargest[i]=st.top();
            st.push(i);
            
        }
        
        
    }
    
    void getprevlargest(vector<int> nums,vector<int>& prevlargest)
    {
         stack<int> st;
         st.push(-1);
        
         for(int i=0;i<nums.size();i++)
        {
            while(st.top()!=-1 && nums[st.top()]<nums[i])
            {
                st.pop();
            }
            
            prevlargest[i]=st.top();
            st.push(i);
            
        }
        
    }
    
    
    void display(vector<int> arr)
    {
        for(int i=0;i<arr.size();i++)
        {
            cout<<arr[i]<<" ";
        }
        
        cout<<endl;
    }
    
    
    
    
    
    long long subArrayRanges(vector<int>& nums) {
        
        vector<int> nextsmallest(nums.size());
        vector<int> prevsmallest(nums.size());
        vector<int> nextlargest(nums.size());
        vector<int> prevlargest(nums.size());
        
         getnextsmallest(nums,nextsmallest);
          getprevsmallest(nums,prevsmallest);
          getnextlargest(nums,nextlargest);
        getprevlargest(nums,prevlargest);
        
       /* display(nextsmallest);
        display(prevsmallest);
        display(nextlargest);
        display(prevlargest);*/
        
        long long sum=0;
        
       for(int i=0;i<nums.size();i++)
        {
            
            if(nextlargest[i]==-1)
            {
                nextlargest[i]=nums.size();
            }
            
            if(nextsmallest[i]==-1)
            {
                nextsmallest[i]=nums.size();
            }
            
            
            long long left1 = i-prevsmallest[i];
            long long left2 = i-prevlargest[i];
            long long right1 = nextsmallest[i]-i;
            long long right2 = nextlargest[i]-i;
            
             long long summax = (left2*right2)*nums[i];
             long long summin = (left1*right1)*nums[i];
            
            sum+=(summax-summin);
            
            
        }
        
        
        return sum;
        
        
        
    }
};
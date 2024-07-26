class Solution {
public:
    
    
    void getnextsmallest(vector<int> arr,vector<int>& nextsmallest)
    {
        
        stack<int> st;
        st.push(-1);
        
        for(int i=nextsmallest.size()-1;i>=0;i--)
        {
            while(st.top()!=-1 && arr[st.top()]>=arr[i])
            {
                st.pop();
            }
            
            nextsmallest[i]=st.top();
            st.push(i);
            
        }
    }
    
    
    void getprevsmallest(vector<int> arr,vector<int>& prevsmallest)
    {
        stack<int> st;
        st.push(-1);
        
        for(int i=0;i<arr.size();i++)
        {
            while(st.top()!=-1 && arr[st.top()]>arr[i])
            {
                st.pop();
            }
            
            prevsmallest[i]=st.top();
            st.push(i);
            
        }
        
    }
    
    
    
    
    
    int sumSubarrayMins(vector<int>& arr) {
        
        
        long long sum=0;
        
        int mod = (int)1e9+7;
        
        vector<int> nextsmallest(arr.size());
        vector<int> prevsmallest(arr.size());
        
        getnextsmallest(arr,nextsmallest);
        getprevsmallest(arr,prevsmallest);
        
        
         // display(nextsmallest);
          //display(prevsmallest);
        
        
        for(int i=0;i<arr.size();i++)
        {
            if(nextsmallest[i]==-1)
            {
                nextsmallest[i]=arr.size();
            }
            
            long long right = nextsmallest[i]-i;
            long long  left = i-prevsmallest[i];
            
           ///cout<<"contri of "<<arr[i]<<" is "<<(right*left)<<endl;
            
            sum= ((sum+(right*left)*arr[i]*1ll)%mod)%mod;
            
        }
        
        
        return sum;
        
    }
};
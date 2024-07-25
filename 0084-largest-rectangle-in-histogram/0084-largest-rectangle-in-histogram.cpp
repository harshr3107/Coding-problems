class Solution {
public:
    
   void display(vector<int> v)
    {
        
        
        for(int i=0;i<v.size();i++)
        {
            cout<<v[i]<<" ";
        }
        
        cout<<endl;
        
    }
    
    
    
    int largestRectangleArea(vector<int>& heights) {
        
        
        vector<int> nextsmallest;
        vector<int> prevsmallest;
        
        stack<int> st1;
        stack<int> st2;
        
        st1.push(-1);
        st1.push(heights[0]);
        prevsmallest.push_back(-1);
        
        int ans = INT_MIN;
        
        st2.push(-1);
        st2.push(heights[heights.size()-1]);
        nextsmallest.push_back(-1);
        
        
        
        for(int i=heights.size()-2;i>=0;i--)
        {
            while(st2.top()>=heights[i])
            {
                st2.pop();
            }
            
            nextsmallest.push_back(st2.top());
            st2.push(heights[i]);
            
        }
        
        
        reverse(nextsmallest.begin(),nextsmallest.end());
        
        
        for(int i=1;i<heights.size();i++)
        {
            
            while(st1.top()>=heights[i])
            {
                st1.pop();
            }
            
            prevsmallest.push_back(st1.top());
            st1.push(heights[i]);
        }
        
        
        
        //display(nextsmallest);
        
        //display(prevsmallest);
        int width;
        
        
        for(int i=0;i<heights.size();i++)
        {
            width=1;
            int n = nextsmallest[i];
            int p = prevsmallest[i];
            int j=i-1;
            
            if(i!=0 && p==-1)
            {
                width+=i-0;
                
            }else{
            
            while(p!=-1 && heights[j]!=p)
            {
                width++;
                j--;
            }
                
            }
            j=i+1;
            
            if(i!=heights.size()-1 && n==-1)
            {
                width=width+(heights.size()-i)-1;
            }else{
            
            while(n!=-1 && heights[j]!=n)
            {
                width++;
                j++;
            }
                
            }
            
            //cout<<"width for element "<<i<<" is "<<width<<endl;
            
            ans = max(ans,heights[i]*width);
            
        }
        
        
        
        
        
        return ans;
        
    }
};
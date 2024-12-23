class Solution {
public:
    
    
    
    
    void display(vector<int>& v)
    {
        for(int i=0;i<v.size();i++)
        {
            cout<<v[i]<<" ";
        }
        
        cout<<endl;
    }
    
    
    
    
    
    void getnextsmallest(vector<int>& height,vector<int>& nextsmallest)
    {
       // cout<<endl;
        stack<int> st;
        st.push(-1);
        
        int i=height.size()-1;
        
        st.push(i);
        
        nextsmallest[i]=-1;
        
        while(i>=0)
        {
            
            while(st.top()!=-1 && height[st.top()]>=height[i])
            {
                st.pop();
            }
            
            nextsmallest[i]=st.top();
            
            st.push(i);
            
            i--;
            
        }
        
        
        
        
    }
    
    
    
    
    
    void getprevsmallest(vector<int>& height,vector<int>& prevsmallest)
    {
        //cout<<endl;
        stack<int> st;
        st.push(-1);
        
        int i=0;
        
        st.push(i);
        
        prevsmallest[i]=-1;
        
        while(i<height.size())
        {
            
            while(st.top()!=-1 && height[st.top()]>=height[i])
            {
                st.pop();
            }
            
            prevsmallest[i]=st.top();
            
            st.push(i);
            
            i++;
            
        }
        
        
        
        
    }
    
    
    
    int getmaxarea(vector<int>& height)
    {
        
        vector<int> nextsmallest(height.size());
        getnextsmallest(height,nextsmallest);
        vector<int> prevsmallest(height.size());
        getprevsmallest(height,prevsmallest);
        
       
        int ans=INT_MIN;
        
        for(int i=0;i<height.size();i++)
        {
            
            if(height[i]==0)
            {
                continue;
            }
            
            if(nextsmallest[i]==-1)
            {
                nextsmallest[i]=height.size();
            }    
            
            ans = max(ans,height[i]*(nextsmallest[i]-prevsmallest[i]-1));
            
        }
        
        
        
        
        
        return ans;
        
        
    }
    
    
    
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        
        vector<int> height(matrix[0].size());
        
        int ans=0;
        
        for(int i=0;i<matrix.size();i++)
        {
            
            for(int j=0;j<matrix[i].size();j++)
            {
                
                if(matrix[i][j]=='1')
                {
                    height[j]+=1;
                }else{
                    
                    height[j]=0;
                }
                
                
            }
            
            //display(height);
            ans = max(ans,getmaxarea(height));
            
            
            
        }
        
        
        
        
        return ans;
    }
};
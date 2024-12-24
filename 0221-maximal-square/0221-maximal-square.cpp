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
    
    
    void getprevsmallest(vector<int>& height,vector<int>& prevsmallest)
    {
        
        
        stack<int> st;
        
        st.push(-1);
        
        int i=0;
        
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
    
    
    
    void getnextsmallest(vector<int>& height,vector<int>& nextsmallest)
    {
        
        
        stack<int> st;
        
        st.push(-1);
        
        int i=height.size()-1;
        
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
    
    
    
    
    
    int getarea(vector<int>& height)
    {
        
        vector<int> prevsmallest(height.size());
        
        getprevsmallest(height,prevsmallest);
        
        vector<int> nextsmallest(height.size());
        
        getnextsmallest(height,nextsmallest);
        
       // display(height);
        //display(nextsmallest);
        //display(prevsmallest);
        
        
      
        
        int area=0;
        
        //calculate area here
        
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
            
            int width = nextsmallest[i]-prevsmallest[i]-1;
            
           // cout<<"widht: "<<width<<" height: "<<height[i]<<endl;
            
            if(height[i]<=width)
            {
                
                int side = min(height[i],width);
                area = max(area,side*side);
            }else{
                
                area=max(area,1);
            }
            
        }
        
        
        
        /*cout<<"area is "<<area<<endl;
          cout<<endl<<endl;*/
        return area;
        
        
        
        
    }
    
    
    
    
    
    
    int maximalSquare(vector<vector<char>>& matrix) {
        
        vector<int> height(matrix[0].size());
        
        
        int ans=0;
        
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[i].size();j++)
            {
                if(matrix[i][j]=='0')
                {
                    height[j]=0;
                }else{
                    
                    height[j]+=1;
                }
                
            }
            
            
            ans=max(ans,getarea(height));
            
            
        }
        
        
        return ans;
        
    }
};
class Solution {
public:
    
    
    
    
    void getallnextsmallest(vector<int> v,stack<int> st,vector<int>& nextsmallest)
    {
        
        for(int i=v.size()-2;i>=0;i--)
        {
            while(st.top()!=-1 && v[st.top()]>=v[i])
            {
                st.pop();
            }
            
            nextsmallest[i]=st.top();
            st.push(i);
            
        }
        
        
        
        
    }
    
    void getallprevsmallest(vector<int> v,stack<int> st,vector<int>& prevsmallest)
    {
        
        for(int i=1;i<v.size();i++)
        {
            while(st.top()!=-1 && v[st.top()]>=v[i])
            {
                st.pop();
            }
            
            prevsmallest[i]=st.top();
            st.push(i);
            
            
        }
        
        
        
    }
    
    
    
    
    
    
    int getminarea(vector<int> v)
    {
        
        int area = 0;
        
        stack<int> st1;
        vector<int> nextsmallest(v.size());
        nextsmallest[v.size()-1]=-1;
        st1.push(-1);
        st1.push(v.size()-1);
        
        
        stack<int> st2;
        vector<int> prevsmallest(v.size());
        st2.push(-1);
        st2.push(0);
        prevsmallest[0]=-1;
        
        getallnextsmallest(v,st1,nextsmallest);
        getallprevsmallest(v,st2,prevsmallest);
        

        
        
        //display(nextsmallest);
        //display(prevsmallest);
        
        
        
        
        
       for(int i=0;i<v.size();i++)
        {
           if(v[i]==0)
           {
               
               continue;
           }
           
            int prev = prevsmallest[i];
            int next = nextsmallest[i];
            
            if(next==-1)
            {
                next=v.size();
            }    
            
            area = max(area, v[i]*(next-prev-1));
            
        }
        
        //cout<<"area is "<<area<<endl;
        
        return area;
        
    }
    
    
    
    
    
    
    
  /*void display(vector<int> v)
    {
         
        for(int i=0;i<v.size();i++)
        {
            cout<<v[i]<<" ";
        }
        
        cout<<endl;
    }
    
    */
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        
        
        int area=INT_MIN;
        
        vector<int> v;
        
        int row=0;
        
        for(int i=0;i<matrix[0].size();i++)
        {
            v.push_back(matrix[row][i]-'0');
        }
        
        //display(v);
        area = getminarea(v);
        
        
        //cout<<"initial area is "<<area<<endl;
        
        
      
        
        
        for(int i=1;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[i].size();j++)
            {
                int num = v[j]+matrix[i][j]-'0';
                
                if(matrix[i][j]=='0')
                {
                    
                     v[j]=0;
                    
                }else{
                    v[j]=num;
                }  
                
                
                
                
                //cout<<v[j]-'0'<<" "<<matrix[i][j]-'0'<<endl;
                //cout<<"value of num is "<<num<<endl;
                 
                
                
                
             }
            
           // display(v);
          //cout<<endl;
            
           area = max(area,getminarea(v));   
            
        }
        
        
        
        
       
        
        
        return area;
        
        
    }
};
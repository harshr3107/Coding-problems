class Solution {
public:
    
    
    void getall(string s, unordered_set<string>& st,int& ans)
    {
       // cout<<"i am here for string "<<s<<endl;
        
        if(s.length()==0)
        {
            
            
            ans = max(ans,static_cast<int>(st.size()));
            
          /*  if(ans==st.size())
            {
                for(auto it : st)
                {
                    cout<<it<<" ";
                }
                cout<<endl;
            }
            */
            return;
        }
        
        int cindex=0;
        
        for(int i=0;i<s.length();i++)
        {
            if(st.count(s.substr(cindex,i+1)))
            {
               continue;
            }
            
            st.insert(s.substr(cindex,i+1));
            getall(s.substr(i+1),st,ans);
            st.erase(s.substr(cindex,i+1));
            
           
        }
        
        
    }
    
    
    
    
    int maxUniqueSplit(string s) {
        
        unordered_set<string> st;
        int ans=INT_MIN;

        
        getall(s,st,ans);
        
        return ans;
        
    }
};
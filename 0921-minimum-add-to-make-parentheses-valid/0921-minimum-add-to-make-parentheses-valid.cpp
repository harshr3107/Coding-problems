class Solution {
public:
    int minAddToMakeValid(string s) {
        
        
        int ans=0;
        stack<char> st;
        
        for(int i=0;i<s.length();i++)
        {
            
            if(s.at(i)=='(')
            {
                st.push(s.at(i));
            }else{
                
                if(st.empty())
                {
                   ans+=1; 
                    continue;
                }    
                    
                st.pop();
                
            }
            
            
            
        }
        
        cout<<"the ans is "<<ans<<endl;
        
        ans+=st.size();
        
        
        return ans;
    }
};
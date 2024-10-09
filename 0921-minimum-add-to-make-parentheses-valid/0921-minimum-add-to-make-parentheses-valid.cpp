class Solution {
public:
    int minAddToMakeValid(string s) {
        
        
        stack<char> st;
        int ans=0;
        
        for(int i=0;i<s.length();i++)
        {
            if(s.at(i)=='(')
            {
                st.push(s.at(i));
            }else{
                
                if(!st.empty())
                {
                    st.pop();
                }else{
                    ans++;
                }
                
                
                
            }
            
        }
        
        ans+=st.size();
        
        return ans;
        
        
    }
};
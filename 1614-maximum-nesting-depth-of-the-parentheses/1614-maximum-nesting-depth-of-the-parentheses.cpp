class Solution {
public:
    int maxDepth(string s) {
        
        stack<char> st;
        
        int ans=0;
        
        for(int i=0;i<s.length();i++)
        {
            if(s.at(i)=='(')
            {
                st.push('(');
               ans = max(ans,static_cast<int>(st.size()));
            }else if(s.at(i)==')')
            {
                st.pop();
            }
            
        }
        
        return ans;
        
    }
};
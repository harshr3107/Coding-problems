class Solution {
public:
    int minLength(string s) {
        
        stack<char> st;
        int i=0;
        
        
        while(i<s.length())
        {
            
            if(st.empty())
            {
                st.push(s.at(i));
                i++;
                continue;
            }
            
            if(s.at(i)=='B' && st.top()=='A')
            {
                
                    st.pop();
                
                
                i++;
                continue;
                
            }
            
            if(s.at(i)=='D' && st.top()=='C')
            {
                   st.pop();
                
                
                i++;
                continue;
            }
            
            
            st.push(s.at(i));
            i++;
            
        }
        
        return st.size();
        
        
        
    }
};
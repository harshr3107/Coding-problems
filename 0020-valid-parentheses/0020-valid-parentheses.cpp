class Solution {
public:
    bool isValid(string s) {
        
        stack<char> st;
        
        
        for(int i=0;i<s.length();i++)
        {
            if(s.at(i)=='(' || s.at(i)=='{' || s.at(i)=='[')
            {
                st.push(s.at(i));
            }else
            {
                
                if(s.at(i)==')')
                {
                    if(!st.empty() && st.top()=='(')
                    {
                        st.pop();
                    }else{
                        
                        return false;
                    }
                    
                }else if(!st.empty() && s.at(i)=='}')
                {
                    if(st.top()=='{')
                    {
                        st.pop();
                    }else{
                        return false;
                    }
                    
                    
                }else if(s.at(i)==']')
                {
                    
                    if(!st.empty() && st.top()=='[')
                    {
                        st.pop();
                    }else{
                        return false;
                    }
                    
                    
                }else{
                    
                    return false;
                }
                
            }
            
            
        }
        
        if(!st.empty())
        {
            return false;
        }
        
        return true;
        
    }
};
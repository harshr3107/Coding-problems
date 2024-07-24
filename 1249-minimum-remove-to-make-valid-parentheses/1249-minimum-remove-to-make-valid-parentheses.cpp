class Solution {
public:
    string minRemoveToMakeValid(string s) {
        
        stack<char> st;
        vector<int> v;
        
        for(int i=0;i<s.length();i++)
        {
            if(s.at(i)=='(')
            {
                st.push(s.at(i));
                v.push_back(i);
                
            }else if(s.at(i)==')')
            {
                
                if(!st.empty() && st.top()=='(')
                {
                    st.pop();
                    v.pop_back();
                }else{
                    
                    s.erase(i,1);
                    i--;
                }
                
                
                
            }else{
                
                continue;
            }
            
        }
        
        
        int num = st.size();
        int a=0;
        
       
        for(int i=0;i<v.size();i++)
        {
            s.erase(v[i]-a,1);
            a++;
        }
        
        
        
        return s;
        
    }
};
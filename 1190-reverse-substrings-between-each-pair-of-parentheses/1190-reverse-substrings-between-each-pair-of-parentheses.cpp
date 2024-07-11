class Solution {
public:
    string reverseParentheses(string s) {
        
        string ans="";
        int i=0;
        int bcount=0;
        stack<char> st;
        
        while(i<s.length())
        {
            
            if(s.at(i)=='(')
            {
                
                
                bcount++;
                st.push(s.at(i));
                
            }else if(s.at(i)==')')
            {
                
                string temp="";
                
                while(st.top()!='(')
                {
                    temp+=st.top();
                    st.pop();
                }
                
                st.pop();
                bcount--;
                if(bcount>=1)
                {
                    int j=0;
                    
                    while(j<temp.length())
                    {
                        st.push(temp.at(j));
                        j++;
                    }
                    
                }else{
                    ans=ans+temp;
                }
                
                
                
            }else{
                
                if(bcount==0)
                {
                    
                    ans+=s.at(i);
                }else{
                
                //cout<<"i am entering here for "<<s.at(i)<<endl;
                st.push(s.at(i));
                }
                
            }
            
            
            i++;
            
            
            
        }
        
        
        return ans;
        
        
    }
};
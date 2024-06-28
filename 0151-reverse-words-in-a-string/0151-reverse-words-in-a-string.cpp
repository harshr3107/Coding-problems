class Solution {
public:
    string reverseWords(string s) {
        
        stack<char> st;
        
        
        for(int i=0;i<s.length();i++)
        {
            
            if(s.at(i)==' ' && (st.empty() || st.top()==' '))
            {
               continue;
                
            }else{
            
                
                st.push(s.at(i));
            }
            
        }
        
        
        
        string temp="";
        s="";
        
        while(!st.empty())
        {
           if(st.top()==' ')
           {
               if(temp!="")
               {
                   s=s+temp+" ";
                   temp="";
               }
               
               
           }else{
               temp=st.top()+temp;
               
           }
            
            st.pop();
            
        }
        
        
       
        s=s+temp;
        
        
        
        
        
        
        
       
        
        return s;
        
        
    }
};
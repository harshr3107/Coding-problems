class Solution {
public:
    
    
    bool check(string h)
    {
        
        stack<char> st;
        
        
        for(int i=0;i<h.length();i++)
        {
            if(h.at(i)=='(')
            {
                st.push(h.at(i));
            }else{
                
                if(st.empty())
                {
                    return false;
                }
                
                st.pop();
                
            }
            
        }
        
        if(!st.empty())
        {
            return false;
        }
        
        
        return true;
        
        
        
    }
    
    
    void getall(string curstr,int opening,int closing,vector<string>& ans)
    {
        if(opening<0 || closing<0)
        {
            return;
        }
        
        if(opening==0 && closing==0)
        {
            //cout<<"checking for "<<curstr<<endl;
            
           if(check(curstr))
           {
               
               ans.push_back(curstr);
           }
            
            return;
        }
        
        //Take opening
        
        curstr.push_back('(');
        getall(curstr,opening-1,closing,ans);
        curstr.pop_back();
        
        //take closing
        
        curstr.push_back(')');
        getall(curstr,opening,closing-1,ans);
        curstr.pop_back();
        
        
        
        
        
    }
    
    
    
    
    
    
    
    
    
    
    vector<string> generateParenthesis(int n) {
        
        int opening = n;
        int closing = n;
        string curstr="";
        
        vector<string> ans;
        
        getall(curstr,opening,closing,ans);
        
        return ans;
        
    }
};
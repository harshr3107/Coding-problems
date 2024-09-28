class Solution {
public:
    int myAtoi(string s) {
        
        
        int i=0;
        string ans;
        int minus=0;
        
        
        while(i<s.length() && s.at(i)==' ')
        {
            i++;
        }
        
        
        if(i<s.length() && s.at(i)=='-')
        {
            i++;
            minus++;
        }else if(i<s.length() && s.at(i)=='+')
        {
            i++;
        }else{
            
        }
        
        
        
        while(i<s.length() && s.at(i)=='0')
        {
            i++;
        }
        
        while(i<s.length() && s.at(i)>='0' && s.at(i)<='9')
        {
            ans+=s.at(i);
            i++;
        }
        
        
        if(ans.length()==0)
        {
            return 0;
        }
        
        cout<<"val of ans is "<<ans<<endl;
        
        int a = pow(2,31)-1;
        
        if(ans.length()>10)
        {
            
            
            if(minus!=0)
            {
                a=0-a;
                
                return a-1;
            }else{
                return a;
            }
            
        }
        
        
        
        
        
        
        
        long long h = stoll(ans);
        
            if(minus==1)
            {
               cout<<"i came here\n";
                a=0-a;
                
                cout<<"val of a is "<<a-1<<endl;
                h=0-h;
                
                if(h<(a-1))
                {
                    cout<<"mai yaha pe bhi aagaya\n";
                    return a-1;
                }
                
                return h;
               
            }else{
                
                if(h>a)
                {
                    return a;
                }
                
                return h;
                
            }
        
        
       
        
        
        
             
            return 0; 
         }
    
        
        
        
    
};
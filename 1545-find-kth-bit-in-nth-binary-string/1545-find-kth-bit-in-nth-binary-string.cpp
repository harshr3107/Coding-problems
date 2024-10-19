class Solution {
public:
    
    
    string reverseinvert(string s)
    {
       //cout<<"i got "<<s<<endl;
        
        if(s.length()==1)
        {
              if(s.at(0)=='0')
            {
                s.at(0)='1';
            }else{
                s.at(0)='0';
            }
             //cout<<"i made "<<s<<endl;
            return s;
            
        }
            
        if(s.length())
        
        
        for(int i=0;i<=(s.length()/2);i++)
        {
            //cout<<"i entered here\n";
            
            if(s.at(i)=='0')
            {
                s.at(i)='1';
            }else{
                s.at(i)='0';
            }
            
            if(i==s.length()-i-1)
            {
                continue;
            }
            
            
            if(s.at(s.length()-i-1)=='0')
            {
                s.at(s.length()-i-1)='1';
            }else{
                
                s.at(s.length()-i-1)='0';
            }
            
            
            char temp = s.at(i);
            s.at(i)=s.at(s.length()-i-1);
            s.at(s.length()-i-1)=temp;
            
            
        }
        
        
       //cout<<"i made "<<s<<endl;
        
        return s;
        
    }
    
    
    
    
    char findKthBit(int n, int k) {
       
    string s = "0";
        
        int i=1;
        
        while(i<n)
        {
            
            //cout<<"string is "<<s<<endl;
            string s2 = reverseinvert(s);
            s=s+"1"+s2;
            i++;
            
            
            
        }
        
        
       // cout<<"string is "<<s<<endl;
        return s.at(k-1);
        
        
        
        
        
        
        
    }
};
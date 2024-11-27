class Solution {
public:
    
    
    void getallans(string s,string cans,vector<string>& v,int coctet)
    {
        //cout<<"the value of cans is "<<cans<<endl;
        
        if(s.length()==0)
        {
            return;
        }
        
        
        if(coctet==4)
        {
            
            long long a = stoll(s);
            //cout<<"i came here for val of a is "<<a<<endl;
            
            
            if(a>=0 && a<=255)
            {
                //cout<<"i came here\n";
                
                if(s.length()>1 && s.at(0)=='0')
                {
                    return;
                }
                v.push_back(cans+to_string(a));
            }
            return;
        }
        
        
        string h="";
        for(int i=0;i<3;i++)
        {
            
            if(s.length()>i)
            {
                
                    if((h.length()>=1 && h.at(0)=='0'))
                    {
                        return;
                    }
                
                
                 h+=s.at(i);
                 int a = stoi(h);
                if(a>=0 && a<=255)
                {
                    
                    
                    string temp=cans;
                    cans+=h;
                    cans.push_back('.');
                   
                    getallans(s.substr(i+1),cans,v,coctet+1);
                    cans=temp;
                    
                    
                }else{
                    return;
                }
                
                
            }
        }
        
        
    }
    
    
    
    
    vector<string> restoreIpAddresses(string s) {
        
        
        vector<string> v;
        string cans="";
        int coctet=1;
        
        getallans(s,cans,v,coctet);
        
        return v;
      
        
    }
};
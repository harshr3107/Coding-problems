class Solution {
public:
    
    int getLCM(vector<int> v)
    {
        int h=v[0];
        
        for(int i=1;i<v.size();i++)
        {
            h = (h*v[i])/gcd(h,v[i]);
        }
       
        return h;
        
    }
    
    void display(vector<int> v)
    {
        for(int i=0;i<v.size();i++)
        {
            cout<<v[i]<<" ";
        }
        
        cout<<endl;
    }
    
    
    
    
    
    string fractionAddition(string s) {
        
       vector<int> divisor;
        vector<int> dividend;
        
        
        int a=0;
        int n=0;
        int i=0;
        int t=0;
        int h=0;
        
        while(i<s.length())
        {
            if(s.at(i)=='-')
            {
                a++;
                h=0;
                t=i+1;
                while(t<s.length() && s.at(t)!='/')
                {
                    t++;
                    h++;
                }
                
                //cout<<"value of h-1 is "<<h<<endl;
                
                n=stoi(s.substr(i+1,h));
                divisor.push_back(-n);
                i=i+1+h+1;
            }
            
            if(s.at(i)=='+')
            {
                i=i+1;
                continue;
            }
            
            if(a%2==0 )
            {
                t=i;
                h=0;
                while(t<s.length() && s.at(t)!='/')
                {
                    t++;
                    h++;
                }
                
                //cout<<"value of h-2 is "<<h<<endl;
                n=stoi(s.substr(i,h));
                divisor.push_back(n);
                a++;
                i=i+h+1;
                
            }else{
                
                t=i;
                h=0;
                 while(t<s.length() && (s.at(t)!='-' && s.at(t)!='+'))
                {
                    t++;
                     h++;
                }
               // cout<<"value of h-3 is "<<h<<endl;
                n=stoi(s.substr(i,h));
                dividend.push_back(n);
                a++;
                i=i+h;
                
                
                
            }
        }
        
         display(divisor);
        display(dividend);
        
        int denominator = getLCM(dividend);
        
        int numerator=0;
        
        for(int i=0;i<divisor.size();i++)
        {
            numerator=numerator+(divisor[i]*(denominator/dividend[i]));
        }
        
        //cout<<"numerator is "<<numerator<<endl;
        
        if(numerator==0)
        {
            return "0/1";
        }
        
        
        int k = gcd(numerator,denominator);
        
        string ans = to_string(numerator/k)+"/"+to_string(denominator/k);
        
        return ans;
    }
};
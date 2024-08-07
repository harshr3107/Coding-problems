class Solution {
public:
    string numberToWords(int num) {
        
        map<int,string> m4;
        m4[1]="";
        m4[2]="Thousand";
        m4[3]="Million";
        m4[4]="Billion";
        m4[5]="Trillion";
        
        map<char,string> m;
        m['1']="One";
        m['2']="Two";
        m['3']="Three";
        m['4']="Four";
        m['5']="Five";
        m['6']="Six";
        m['7']="Seven";
        m['8']="Eight";
        m['9']="Nine";
        
        map<char,string> m2;
        m2['1']="One";
        m2['2']="Twenty";
        m2['3']="Thirty";
        m2['4']="Forty";
        m2['5']="Fifty";
        m2['6']="Sixty";
        m2['7']="Seventy";
        m2['8']="Eighty";
        m2['9']="Ninety";
        
        
        map<char,string> m3;
        m3['1']="Eleven";
        m3['2']="Twelve";
        m3['3']="Thirteen";
        m3['4']="Fourteen";
        m3['5']="Fifteen";
        m3['6']="Sixteen";
        m3['7']="Seventeen";
        m3['8']="Eighteen";
        m3['9']="Nineteen";
        m3['0']="Ten";
        
        vector<string> v;
        
        string nums = to_string(num);
        
       int i=nums.size()-1;
        
        while(i>=0)
        {
           
            
            if((i-2)>=0)
            {
                
                string  s = nums.substr(i-2,3);
                cout<<s<<endl;
                v.push_back(s);
                i=i-3;
               
                
            }else if((i-1)>=0)
            {
               
                string  s = nums.substr(i-1,2);
                v.push_back(s);
                i=i-2;
                break;
            }else if(i==0)
            {
                
                string  s = nums.substr(i,1);
                v.push_back(s);
                i=i-1;
                break;
                
            }else{
                 continue;
            }
            
            
        }
        
        vector<string> v2;
        string s;
        
        int a=0;
        
        for(int i=0;i<v.size();i++)
        {
            int n = v[i].size();
            a=0;
            
            if(n==3)
            {
                
                 if(v[i].at(0)!='0')
                {
                     
                    s+=m[v[i].at(0)];
                    s=s+" Hundred ";
                }
                
                 if(v[i].at(1)!='0')
                {
                     if(v[i].at(1)!='1')
                     {
                     
                        s+=m2[v[i].at(1)];
                         
                     }else{
                         
                         s=s+m3[v[i].at(2)];
                         a++;
                     }
                     
                     s=s+" ";
                   
                }
                
                
                
                if(v[i].at(2)!='0' && a==0)
                {
                    s+=m[v[i].at(2)];
                    s=s+" ";
                }
                
               
                
               
                
                v2.push_back(s);
                
                s="";
                
            }else if(n==2)
            {
                
                
                 if(v[i].at(0)!='0')
                {
                     if(v[i].at(0)!='1')
                     {
                     
                     s+=m2[v[i].at(0)];
                         
                     }else{
                         
                        
                         a++;
                         s+=m3[v[i].at(1)];
                         
                     }   
                         
                     s=s+" ";
                    
                   
                }
                
                
                
                if(v[i].at(1)!='0' && a==0)
                {
                    s+=m[v[i].at(1)];
                    s=s+" ";
                }
                
                 v2.push_back(s);
                 
                
                
                s="";
                
                
                
            }else if(n==1)
            {
                s=s+m[v[i].at(0)];
                s=s+" ";
                v2.push_back(s);
                s="";
                
            }else{
                
                continue;
            }
            
        }
        
        
        
        
        
        string ans="";
        
        for(int i=v2.size()-1;i>=0;i--)
        {
            
            if(v2[i].length()!=0)
            {
            
            ans=ans+v2[i]+m4[i+1]+" ";
            
                //cout<<v2[i]<<m4[i+1]<<" ";
            }
        }
        
        
        if(ans=="  ")
        {
          return "Zero";  
        }
        
        a=0;
       i=ans.length()-1;
        while(ans[i]==' ')
        {
            a++;
            i--;
        }
        
        
        
        
       return ans.erase(ans.length()-a); 
        
    }
};
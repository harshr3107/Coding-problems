class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        int num=0;
        int cnum=0;
        int s2len = s2.length();
        int s1len = s1.length();
        
        for(int i=0;i<s1len;i++)
        {
            num=num+(s1.at(i)-'a');
        }
        
        //cout<<"value of num is "<<num<<endl;
        
        int i=0;
        //sort(s1.begin(),s1.end());
        
        while(i<(s2len-s1len+1))
        {
            //cout<<"value of str is "<<h<<endl;
            //sort(s1.begin(),s1.end());
            //sort(h.begin(),h.end());
            
            /*if(s1==h)
            {
                return true;
            }*/
            
            //i++;
            
                
           string h = s2.substr(i,s1len);  
                
            int j=0;
            while(j<s1len)
            {
                cnum+=h.at(j)-'a';
                j++;
            }
            
           // cout<<"value of cnum is "<<cnum<<endl;
            
            if(cnum==num)
            {
                int j=0;
                while(j<s1.length() && h.find(s1.at(j))<s1.length())
                {
                    j++;
                }
                
                //cout<<"value of j is "<<j<<endl;
                
                if(j==s1len)
                {
                return true;
                }
            }
            
            cnum=0;
            i++;
            
        }
        
        
        return false;
        
        
        
        
    }
};
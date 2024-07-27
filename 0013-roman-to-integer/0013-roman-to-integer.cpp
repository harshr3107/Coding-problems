class Solution {
public:
    int romanToInt(string s) {
        
       map<char,int> m;
        m['I']=1;
        m['V']=5;
        m['X']=10;
        m['L']=50;
        m['C']=100;
        m['D']=500;
        m['M']=1000;
        
        int sum=0;
        
        int i=s.length()-1;
        int j=i;
        
       // cout<<"value of i is "<<i<<endl;
        
        while(i>=0)
        {
            //cout<<"value of i is "<<i<<endl;
            int num=m[s.at(i)];
            j=i-1;
            
            while(j>=0 && m[s.at(i)]>m[s.at(j)])
            {
                num=num-m[s.at(j)];
                j--;
            }
            // cout<<"value of j is "<<j<<endl;
            
            sum=sum+num;
            //cout<<"value of sum is "<<sum<<endl;
            
            i=j;
            
           
            
            
            
        }
        
        
        return sum;
        
        
        
        
        
        
    }
};
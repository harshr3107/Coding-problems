class Solution {
public:
    int secondsToRemoveOccurrences(string s) {
        
        int ans=0;
        
        while(true)
        {
            int i=1;
            int a=0;
            
            while(i<s.length())
            {
                if(s.at(i-1)=='0' && s.at(i)=='1')
                {
                    a++;
                   swap(s.at(i-1),s.at(i));
                   i++;
                }
                
                i++;
                
            }
            
            if(a==0)
            {
                break;
            }else{
                ans++;
            }
            
            
        }
        
        cout<<"value of ans is "<<ans<<endl;
        
        
        return ans;
        
    }
};
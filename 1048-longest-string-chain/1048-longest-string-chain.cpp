class Solution {
public:
    
    bool compare(string a,string b)
    {
        
            if(abs(static_cast<int>(a.length())-static_cast<int>(b.length()))!=1)
            {
                return false;
            }
        
       // sort(a.begin(),a.end());
        //sort(b.begin(),b.end());
        
        if(a.length()<b.length())
        {
            string temp = b;
            b=a;
            a=temp;
            
        }
        
        //cout<<a<<" "<<b<<endl;
        
        
        int i=0;
        int j=0;
        int dif=0;
        
        while(i<a.length() && j<b.length())
        {
            
            if(a.at(i)==b.at(j))
            {
                i++;
                j++;
            }else{
                
                i++;
                dif++;
            }
            
        }
        
        if(i!=a.length() && dif==1)
        {
            return false;
        }
        
        if(dif>=2)
        {
            return false;
        }
        
        return true;
        
        
        
        }
    
    
    bool static comp(string a,string b)
    {
        return a.length()<b.length();
    }
    
    
    
  
    
    
    
    int longestStrChain(vector<string>& words) {
        
        sort(words.begin(),words.end(),comp);
        
        /*for(int i=0;i<words.size();i++)
        {
            cout<<words[i]<<" ";
        }
        
        cout<<endl<<endl;*/
        
        vector<int> dp(words.size(),1);
        
        
        for(int i=0;i<words.size();i++)
        {
            
            for(int j=0;j<=i;j++)
            {
                
                if(compare(words[i],words[j]) && dp[j]+1>dp[i])
                {
                    dp[i]=dp[j]+1;
                }
                
            }
            
            
        }
        
        
        int ans = *max_element(dp.begin(),dp.end());
        
        return ans;
        
    }
};